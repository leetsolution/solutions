import os
import json
import time
from datetime import datetime, timezone
from dotenv import load_dotenv
import requests


def load_api_keys():
    load_dotenv()
    keys_env = os.environ.get("GEMINI_API_KEYS")
    if keys_env:
        keys = [k.strip() for k in keys_env.split(",") if k.strip()]
    else:
        single = os.environ.get("GEMINI_API_KEY")
        keys = [single] if single else []
    return keys


GEMINI_API_KEYS = load_api_keys()
MODEL_URL = "https://generativelanguage.googleapis.com/v1/models/gemini-1.5-flash:generateContent"


def list_problem_folders(root: str):
    problems_dir = os.path.join(root, "problems")
    if not os.path.isdir(problems_dir):
        return []
    return [
        os.path.join(problems_dir, name)
        for name in os.listdir(problems_dir)
        if os.path.isdir(os.path.join(problems_dir, name))
    ]


def pick_best_solution(folder: str):
    # Prefer python, then java, then cpp, then c
    candidates = [
        ("python3", "solution.py"),
        ("java", "solution.java"),
        ("cpp", "solution.cpp"),
        ("c", "solution.c"),
    ]
    for lang, fname in candidates:
        path = os.path.join(folder, fname)
        if os.path.isfile(path):
            try:
                with open(path, "r", encoding="utf-8") as f:
                    return lang, f.read()
            except Exception:
                continue
    return None, None


def read_problem_json(folder: str):
    pj = os.path.join(folder, "problem.json")
    if not os.path.isfile(pj):
        return None, pj
    try:
        with open(pj, "r", encoding="utf-8") as f:
            return json.load(f), pj
    except Exception:
        return None, pj


def call_gemini_complexity(code: str, title: str, difficulty: str, api_keys: list, start_idx: int = 0):
    if not api_keys:
        raise RuntimeError("No GEMINI_API_KEYS configured in .env")

    prompt = (
        "You are a strict complexity analyzer. Given the code below, infer the dominant time and space complexity "
        "in Big-O notation for typical inputs. Respond ONLY with a compact JSON object in this exact shape: "
        "{\"time\": \"O(x)\", \"space\": \"O(y)\"}. Do not add any extra text.\n\n"
        f"Title: {title}\n"
        f"Difficulty: {difficulty}\n\n"
        "Code:\n" + code
    )

    payload = {"contents": [{"parts": [{"text": prompt}]}]}

    max_attempts = max(3, 2 * len(api_keys))
    key_idx = start_idx % len(api_keys)
    last_error = None

    for attempt in range(1, max_attempts + 1):
        key = api_keys[key_idx]
        print(f"[complexity] Attempt {attempt}/{max_attempts} using API key index {key_idx}")
        try:
            resp = requests.post(MODEL_URL, params={"key": key}, json=payload, timeout=60)
            if resp.status_code == 429:
                last_error = "429 Too Many Requests"
                key_idx = (key_idx + 1) % len(api_keys)
                time.sleep(3)
                continue
            resp.raise_for_status()
            data = resp.json()
            text = (
                data.get("candidates", [{}])[0]
                .get("content", {})
                .get("parts", [{}])[0]
                .get("text", "")
                .strip()
            )
            if not text:
                last_error = "Empty response"
                key_idx = (key_idx + 1) % len(api_keys)
                time.sleep(1)
                continue
            # Attempt to parse JSON strictly
            try:
                obj = json.loads(text)
                time_c = obj.get("time")
                space_c = obj.get("space")
                if isinstance(time_c, str) and isinstance(space_c, str):
                    return obj, key_idx
            except Exception:
                # Try to extract via simple regex fallback
                import re
                mt = re.search(r'"time"\s*:\s*"([^"]+)"', text)
                ms = re.search(r'"space"\s*:\s*"([^"]+)"', text)
                if mt and ms:
                    return {"time": mt.group(1), "space": ms.group(1)}, key_idx
                last_error = f"Non-JSON response: {text[:120]}..."
                key_idx = (key_idx + 1) % len(api_keys)
                time.sleep(1)
                continue
        except Exception as e:
            last_error = str(e)
            key_idx = (key_idx + 1) % len(api_keys)
            time.sleep(2)

    raise RuntimeError(f"Gemini analysis failed after {max_attempts} attempts. Last error: {last_error}")


def update_problem_json(pjson: dict, pj_path: str, result: dict):
    """Write complexity fields at the top level and remove any nested 'analysis'."""
    if not isinstance(pjson, dict):
        return False
    # Remove legacy nested analysis block if present
    if "analysis" in pjson:
        pjson.pop("analysis", None)

    # Write top-level fields only
    pjson["time_complexity"] = result.get("time")
    pjson["space_complexity"] = result.get("space")

    try:
        with open(pj_path, "w", encoding="utf-8") as f:
            json.dump(pjson, f, indent=2)
        return True
    except Exception:
        return False


def main():
    root = os.path.dirname(os.path.abspath(__file__))
    folders = list_problem_folders(root)
    if not folders:
        print("No problems/ folders found.")
        return

    api_start_idx = 0
    processed = 0
    skipped = 0
    failed = 0

    for folder in folders:
        pjson, pj_path = read_problem_json(folder)
        if not pjson:
            print(f"Skipping {folder}: missing or invalid problem.json")
            skipped += 1
            continue

        # If already has top-level complexity, skip
        if pjson.get("time_complexity") and pjson.get("space_complexity"):
            print(f"Skipping {pjson.get('number')}. {pjson.get('title')}: already has complexity")
            skipped += 1
            continue

        # Migrate from nested analysis if present
        if isinstance(pjson.get("analysis"), dict):
            a = pjson["analysis"]
            t = a.get("time_complexity")
            s = a.get("space_complexity")
            if t and s:
                pjson["time_complexity"] = t
                pjson["space_complexity"] = s
                # remove nested analysis to align with new schema
                pjson.pop("analysis", None)
                try:
                    with open(pj_path, "w", encoding="utf-8") as f:
                        json.dump(pjson, f, indent=2)
                    print(f"Migrated analysis to top-level for {pjson.get('number')}. {pjson.get('title')}")
                    processed += 1
                    continue
                except Exception:
                    print(f"Failed to migrate analysis for {pjson.get('number')}. {pjson.get('title')}")
                    # fall through to try live analysis

        lang, code = pick_best_solution(folder)
        if not code:
            print(f"Skipping {pjson.get('number')}. {pjson.get('title')}: no solution file found")
            skipped += 1
            continue

        title = pjson.get("title", "")
        difficulty = pjson.get("difficulty", "")

        try:
            result, api_start_idx = call_gemini_complexity(code, title, difficulty, GEMINI_API_KEYS, api_start_idx)
            ok = update_problem_json(pjson, pj_path, result)
            if ok:
                print(f"Analyzed {pjson.get('number')}. {title}: {result}")
                processed += 1
            else:
                print(f"Failed to write analysis for {pjson.get('number')}. {title}")
                failed += 1
        except Exception as e:
            print(f"Analysis failed for {pjson.get('number')}. {title}: {e}")
            failed += 1
            # small pause to reduce hammering on errors
            time.sleep(1)

        # polite pause
        time.sleep(0.3)

    print(f"Done. processed={processed}, skipped={skipped}, failed={failed}")


if __name__ == "__main__":
    main()
