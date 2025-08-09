import os
import json
import re
from typing import Dict, List, Optional


ROOT = os.path.dirname(os.path.abspath(__file__))
PROBLEMS_DIR = os.path.join(ROOT, "problems")
TOPICS_DIR = os.path.join(ROOT, "topics")


def slugify_topic(name: str) -> str:
    """Convert topic name to a kebab-case folder slug.
    Examples: "Hash Table" -> "hash-table", "Depth-First Search" -> "depth-first-search".
    """
    s = name.strip().lower()
    # replace non-alphanumeric with hyphens
    s = re.sub(r"[^a-z0-9]+", "-", s)
    s = re.sub(r"-+", "-", s).strip("-")
    return s or "unknown"


def read_problem_json(folder: str) -> Optional[dict]:
    pj = os.path.join(folder, "problem.json")
    if not os.path.isfile(pj):
        return None
    try:
        with open(pj, "r", encoding="utf-8") as f:
            data = json.load(f)
            return data if isinstance(data, dict) else None
    except Exception:
        return None


def collect_problems() -> List[dict]:
    if not os.path.isdir(PROBLEMS_DIR):
        return []
    items = []
    for name in os.listdir(PROBLEMS_DIR):
        pdir = os.path.join(PROBLEMS_DIR, name)
        if not os.path.isdir(pdir):
            continue
        data = read_problem_json(pdir)
        if not data:
            continue
        # minimal validation
        if not all(k in data for k in ("number", "title", "slug", "difficulty", "topics")):
            continue
        if not isinstance(data.get("topics"), list):
            continue
        items.append(data)
    return items


def build_topic_index(problems: List[dict]) -> Dict[str, List[dict]]:
    """Return mapping of topic_slug -> list of minimal problem entries."""
    index: Dict[str, Dict[str, dict]] = {}
    for p in problems:
        num = p.get("number")
        title = p.get("title")
        slug = p.get("slug")
        difficulty = p.get("difficulty")
        entry = {
            "number": str(num) if num is not None else "",
            "title": title,
            "slug": slug,
            "difficulty": difficulty,
        }
        for t in p.get("topics", []):
            if not isinstance(t, str) or not t.strip():
                continue
            tslug = slugify_topic(t)
            bucket = index.setdefault(tslug, {})
            # use slug as unique key to avoid duplicates
            bucket[slug] = entry

    # convert inner dicts to sorted lists
    result: Dict[str, List[dict]] = {}
    for tslug, by_slug in index.items():
        lst = list(by_slug.values())
        def sort_key(e: dict):
            # sort by numeric number then slug
            try:
                n = int(str(e.get("number", "0")).strip())
            except ValueError:
                n = 10**9
            return (n, e.get("slug", ""))

        lst.sort(key=sort_key)
        result[tslug] = lst
    return result


def ensure_dir(path: str):
    os.makedirs(path, exist_ok=True)


def write_topic_files(index: Dict[str, List[dict]]):
    ensure_dir(TOPICS_DIR)
    written = 0
    for tslug, items in index.items():
        tdir = os.path.join(TOPICS_DIR, tslug)
        ensure_dir(tdir)
        out_path = os.path.join(tdir, "problems.json")
        with open(out_path, "w", encoding="utf-8") as f:
            json.dump(items, f, indent=2)
        written += 1
    return written


def main():
    problems = collect_problems()
    if not problems:
        print("No problems found to index.")
        return
    index = build_topic_index(problems)
    count = write_topic_files(index)
    print(f"Wrote {count} topic file(s). Topics indexed: {len(index)}")


if __name__ == "__main__":
    main()
