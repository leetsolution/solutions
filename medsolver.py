from bs4 import BeautifulSoup
import re
import os
from dotenv import load_dotenv
import requests
import time
import json
from datetime import datetime, timezone

def clean_html_to_text(html: str) -> str:
    """
    Converts HTML content into a single plain-text paragraph.
    Preserves key inline formatting like <code> as backticks.
    Removes all tags, excessive whitespace, and line breaks.
    """
    soup = BeautifulSoup(html, 'html.parser')

    # Replace <code> tags with inline backtick text
    for code in soup.find_all("code"):
        code.replace_with(f"`{code.get_text(strip=True)}`")

    # Unwrap <sup> tags
    for sup in soup.find_all("sup"):
        sup.unwrap()

    # Add bullet or numbered prefix to list items
    for ul in soup.find_all("ul"):
        for li in ul.find_all("li"):
            li.insert_before("- ")

    for ol in soup.find_all("ol"):
        for idx, li in enumerate(ol.find_all("li"), 1):
            li.insert_before(f"{idx}. ")

    # Get the full text
    text = soup.get_text(separator=' ', strip=True)

    # Replace multiple spaces and remove newlines
    text = re.sub(r'\s+', ' ', text)

    return text.strip()


def get_available_languages(slug):
    query = """
    query getQuestionDetail($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        codeSnippets {
          langSlug
        }
      }
    }
    """
    variables = {"titleSlug": slug}
    try:
        resp = requests.post(GRAPHQL_URL, json={"query": query, "variables": variables}, headers=HEADERS, timeout=15)
        data = resp.json()
        code_snippets = data['data']['question'].get('codeSnippets')
        if not code_snippets:
            return []
        return [snippet['langSlug'] for snippet in code_snippets]
    except Exception as e:
        print(f"  Error fetching available languages: {e}")
        return []
import re
def slugify_title(title):
    slug = title.lower()
    slug = re.sub(r'[^a-z0-9\s]', '', slug)
    slug = re.sub(r'\s+', '-', slug)
    slug = re.sub(r'-+', '-', slug)
    slug = slug.strip('-')
    return slug

def get_problem_metadata(slug):
    query = """
    query getQuestionDetail($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        questionFrontendId
        title
        content
        difficulty
        topicTags { name slug }
      }
    }
    """
    variables = {"titleSlug": slug}
    try:
        resp = requests.post(GRAPHQL_URL, json={"query": query, "variables": variables}, headers=HEADERS, timeout=15)
        data = resp.json()
        q = data['data']['question']
        return {
            'number': q['questionFrontendId'],
            'title': q['title'],
            'content': q['content'],
            'difficulty': q['difficulty'],
            'topics': q['topicTags']
        }
    except Exception as e:
        print(f"  Error fetching problem metadata: {e}")
        return {
            'number': '', 'title': '', 'content': '', 'difficulty': '', 'topics': []
        }
# Gemini API integration

# Load environment variables from .env

# Load environment variables from .env
load_dotenv()
# Support multiple Gemini API keys and models
GEMINI_API_KEYS = os.environ.get("GEMINI_API_KEYS", "").split(",") if os.environ.get("GEMINI_API_KEYS") else [os.environ.get("GEMINI_API_KEY")]
api_key_idx = 0  # Global API key index
GEMINI_MODELS = [
    "https://generativelanguage.googleapis.com/v1/models/gemini-1.5-flash:generateContent",
    "https://generativelanguage.googleapis.com/v1/models/gemini-1.5-pro:generateContent",
    "https://generativelanguage.googleapis.com/v1/models/gemini-2.0-flash:generateContent",
    "https://generativelanguage.googleapis.com/v1/models/gemini-2.5-pro:generateContent"
]

def get_problem_content(slug):
    query = """
    query getQuestionDetail($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        content
        title
      }
    }
    """
    variables = {"titleSlug": slug}
    resp = requests.post(GRAPHQL_URL, json={"query": query, "variables": variables}, headers=HEADERS)
    data = resp.json()
    q = data['data']['question']
    return q['title'], q['content']


def generate_solution_with_gemini(starter_code, problem_title, problem_content, language, difficulty):
    """
    Generate solution using Gemini model selected by difficulty, with API key/model rotation on rate limit errors.
    """
    global api_key_idx
    # Use gemini-2.0-flash for easy, gemini-2.5-pro for medium/hard
    if difficulty and difficulty.lower() == "easy":
        model_url = "https://generativelanguage.googleapis.com/v1/models/gemini-2.0-flash:generateContent"
    elif difficulty and difficulty.lower() == "medium":
        model_url = "https://generativelanguage.googleapis.com/v1/models/gemini-1.5-pro:generateContent"
    else:
        model_url = "https://generativelanguage.googleapis.com/v1/models/gemini-2.5-pro:generateContent"

    max_retries = 3 * len(GEMINI_API_KEYS)
    key_rotations = 0

    prompt = f"""Solve the following LeetCode problem in {language}:

Title: {problem_title}

Description:
{problem_content}

Requirements:
- Use the correct LeetCode problem number and title.
- Should Start with the given starter code no modification on it.
- Ensure the solution is optimal and passes all test cases.
- Do not include any comments or explanations in the code or before the code.
- Respond with only the complete code in {language}, no explanation ONLY CODE.

Starter Code:
```{language}
{starter_code.strip()}
```"""

    payload = {
        "contents": [{"parts": [{"text": prompt}]}]
    }

    for attempt in range(1, max_retries + 1):
        params = {"key": GEMINI_API_KEYS[api_key_idx]}
        print(f"Using API key {api_key_idx} for this attempt.")
        try:
            response = requests.post(model_url, params=params, json=payload, timeout=1000)
            response.raise_for_status()
            result = response.json()

            if 'candidates' in result and result['candidates']:
                text = result['candidates'][0]['content']['parts'][0]['text'].strip()
                if text:
                    return text
            print(f"[Attempt {attempt}] Gemini API returned empty or invalid response.")
        except Exception as e:
            print(f"[Attempt {attempt}] Gemini API error: {e}")
            # If rate limit error, rotate API key, do not reset until all keys are tried
            if hasattr(e, 'response') and e.response is not None and e.response.status_code == 429:
                api_key_idx += 1
                key_rotations += 1
                if api_key_idx >= len(GEMINI_API_KEYS):
                    api_key_idx = 0
                print(f"Switching to API key {api_key_idx} due to rate limit.")
            if attempt < max_retries:
                wait_time = 5 * attempt
                print(f"Retrying in {wait_time} seconds...")
                time.sleep(wait_time)

    print("\n--- Gemini Prompt Debug ---\n", prompt, "\n--- End Prompt ---")
    return f"# Gemini did not return a valid solution for '{problem_title}' in {language} after {max_retries} attempts."

LEETCODE_SESSION = "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJhY2NvdW50X3ZlcmlmaWVkX2VtYWlsIjpudWxsLCJfYXV0aF91c2VyX2lkIjoiMTg2NTg1MzAiLCJfYXV0aF91c2VyX2JhY2tlbmQiOiJhbGxhdXRoLmFjY291bnQuYXV0aF9iYWNrZW5kcy5BdXRoZW50aWNhdGlvbkJhY2tlbmQiLCJfYXV0aF91c2VyX2hhc2giOiJmYzAxMTNmMjYyZjdkNTJhYjMwNmVhM2ZkYjhkOGVlNzMxYzYyYTQ1ZjYyZGU1MDk5ZWE3MmI2YjIwY2E0NGY2Iiwic2Vzc2lvbl91dWlkIjoiYTg5MDc3NjkiLCJpZCI6MTg2NTg1MzAsImVtYWlsIjoibXNhc3dhdGExNWdkc2NAZ21haWwuY29tIiwidXNlcm5hbWUiOiJLREY3SlFldFhBIiwidXNlcl9zbHVnIjoiS0RGN0pRZXRYQSIsImF2YXRhciI6Imh0dHBzOi8vYXNzZXRzLmxlZXRjb2RlLmNvbS91c2Vycy9kZWZhdWx0X2F2YXRhci5qcGciLCJyZWZyZXNoZWRfYXQiOjE3NTQyMzY2NDIsImlwIjoiMjQwNToyMDE6OTAwZjoxOGU1Ojk1NGY6MmEyZTpiYzo4MGNhIiwiaWRlbnRpdHkiOiI3ZGRlZGE4OGQwYzU5OWNjNDk0ZGEwZGVjZTY1NTRkNSIsImRldmljZV93aXRoX2lwIjpbIjUyMjg5MDFlYjAyOGFmZWQ3ODE5MWYyNjg4NGMyMTQ1IiwiMjQwNToyMDE6OTAwZjoxOGU1Ojk1NGY6MmEyZTpiYzo4MGNhIl19.3oPWKwIr-QfrPXq6O5ZynELtJ4eWoWTt4dbA_KXqMYY"

HEADERS = {
    "User-Agent": "Mozilla/5.0",
    "Cookie": f"LEETCODE_SESSION={LEETCODE_SESSION}"
}

PROBLEM_LIST_URL = "https://leetcode.com/api/problems/all/"
GRAPHQL_URL = "https://leetcode.com/graphql"
LANGUAGES = {
    "python3": "solution.py",
    "java": "solution.java",
    "cpp": "solution.cpp",
    "c": "solution.c"
}

def get_problem_slugs():
    resp = requests.get(PROBLEM_LIST_URL, headers=HEADERS)
    data = resp.json()
    slugs = [p['stat']['question__title_slug'] for p in data['stat_status_pairs']]
    return slugs

def get_starter_code(slug, lang):
    query = """
    query getQuestionDetail($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        codeSnippets {
          lang
          langSlug
          code
        }
      }
    }
    """
    variables = {"titleSlug": slug}
    try:
        resp = requests.post(GRAPHQL_URL, json={"query": query, "variables": variables}, headers=HEADERS, timeout=15)
        data = resp.json()
        snippets = data['data']['question']['codeSnippets']
        for snippet in snippets:
            if snippet['langSlug'] == lang:
                return snippet['code']
        return None
    except Exception as e:
        print(f"  Error fetching starter code for {lang}: {e}")
        return None

def merge_starter_and_gemini(starter_code, gemini_body, lang):
    """
    Clean Gemini's output and return it directly, ignoring starter code and language merging.
    """
    if not gemini_body:
        return ''
    import re
    # Extract only the code block from Gemini output
    code_blocks = re.findall(r'```[a-zA-Z0-9]*\n([\s\S]*?)```', gemini_body)
    if code_blocks:
        code = code_blocks[0].strip()
        return code
    # Fallback: try to remove markdown artifacts and return remaining text
    gemini_body = re.sub(r'^```.*$', '', gemini_body, flags=re.MULTILINE)
    gemini_body = re.sub(r'^```$', '', gemini_body, flags=re.MULTILINE)
    return gemini_body.strip()

def main():
    visited_json_path = "visited_problems.json"
    # Load existing visited problems as {slug: [languages]}
    if os.path.exists(visited_json_path):
        with open(visited_json_path, "r", encoding="utf-8") as f:
            try:
                loaded = json.load(f)
                # If loaded is a list, convert to dict
                if isinstance(loaded, list):
                    visited = {slug: [] for slug in loaded}
                elif isinstance(loaded, dict):
                    visited = loaded
                else:
                    visited = {}
            except Exception:
                visited = {}
    else:
        visited = {}

    slugs = get_problem_slugs()
    topic_map = {}
    import random
    # Find the last visited problem index
    last_visited_idx = -1
    for i, slug in enumerate(slugs):
        if slug in visited:
            last_visited_idx = i
    # Start processing from the next problem after the last visited
    for slug in slugs[last_visited_idx+1:]:
        available_langs = get_available_languages(slug)
        # Skip if only SQL or unsupported languages are available
        if not any(lang in available_langs for lang in LANGUAGES.keys()):
            print(f"Skipping {slug}: only SQL or unsupported languages.")
            continue
        meta = get_problem_metadata(slug)
        difficulty = meta['difficulty']
        if not difficulty or difficulty.lower() != "medium":
            print(f"Skipping {slug}: not an medium problem.")
            continue
        number = meta['number']
        title = meta['title']
        content = meta['content']
        cleaned_content = clean_html_to_text(content)
        topics = meta['topics']
        # Only solve if 'String' is present in topics (either as a dict with name 'String' or as a string in the list)
        topic_names = [t['name'] if isinstance(t, dict) and 'name' in t else t for t in topics]
        if 'String' not in topic_names:
            print(f"Skipping {slug}: 'String' topic not found.")
            continue
        folder_name = f"problems/{str(number).zfill(3)}-{slugify_title(title)}"
        created_folder = False
        written_code = False
        for lang, filename in LANGUAGES.items():
            if lang not in available_langs:
                print(f"  Skipping {filename}: not available for this problem.")
                continue
            # Skip this language if already present for the slug
            if slug in visited and lang in visited[slug]:
                print(f"  Skipping {slug} for {lang}: already visited.")
                continue
            try:
                starter_code = get_starter_code(slug, lang)
                print(f"    Starter code for {lang}:\n{starter_code}\n---")
                print(type(starter_code))
                print(type(title))
                print(type(content))
                print(f"Title: {title}, Cleaned Content: {cleaned_content}, Language: {lang}, Difficulty: {difficulty}")
                # Always ask Gemini for a solution body, passing difficulty
                gemini_body = generate_solution_with_gemini(starter_code, title, cleaned_content, lang, difficulty)
                print(f"    Gemini code for {lang}:\n{gemini_body}\n---")
                # Only proceed if Gemini returned a valid response
                if gemini_body and gemini_body.strip() != '' and not gemini_body.strip().startswith('# Gemini did not return'):
                    if not created_folder:
                        os.makedirs(folder_name, exist_ok=True)
                        print(f"Processing {number}. {title} -> {folder_name}")
                        # Save README.md
                        with open(os.path.join(folder_name, "README.md"), "w", encoding="utf-8") as f:
                            f.write(f"# {number}. {title}\n\n## Problem Statement\n{content}\n\n## Difficulty\n{difficulty}\n\n## Topics\n{', '.join([t['name'] for t in topics if isinstance(t.get('name', None), str)])}\n")
                        print(f"  Wrote README.md")
                        # Save problem.json with metadata
                        problem_data = {
                            "number": number,
                            "title": title,
                            "description": content,
                            "difficulty": difficulty,
                            "topics": [t["name"] for t in topics if isinstance(t.get('name', None), str)],
                            "slug": slug,
                            "url": f"https://leetcode.com/problems/{slug}/",
                            "timestamp": datetime.now(timezone.utc).isoformat()
                        }
                        with open(os.path.join(folder_name, "problem.json"), "w", encoding="utf-8") as f:
                            json.dump(problem_data, f, indent=2)
                        print(f"  Wrote problem.json")
                        created_folder = True
                    # Insert Gemini's code into the starter code
                    completed_code = merge_starter_and_gemini(starter_code, gemini_body, lang)
                    if completed_code and completed_code.strip() != '':
                        with open(os.path.join(folder_name, filename), "w", encoding="utf-8") as f:
                            f.write(completed_code)
                        print(f"  Wrote {filename}")
                        written_code = True
                        # Update visited: add slug and lang and save immediately
                        if slug not in visited:
                            visited[slug] = []
                        if lang not in visited[slug]:
                            visited[slug].append(lang)
                        with open(visited_json_path, "w", encoding="utf-8") as vf:
                            json.dump(visited, vf, indent=2)
                    else:
                        print(f"  No code generated for {filename}.")
                else:
                    print(f"  No valid Gemini response for {filename}. Skipping this question.")
                # Sleep 0-1 seconds to avoid Gemini API rate limits
                sleep_time = 0
                print(f"  Sleeping {sleep_time} seconds to avoid Gemini rate limit...")
                time.sleep(sleep_time)
            except requests.exceptions.HTTPError as e:
                print(f"  Gemini API error for {lang}: {e}")
        # Add to topic map for sorting only if folder was created and code written
        if created_folder and written_code:
            for t in topics:
                tslug = t['slug']
                if tslug not in topic_map:
                    topic_map[tslug] = []
                topic_map[tslug].append({
                    'number': number,
                    'title': title,
                    'slug': slug,
                    'difficulty': difficulty
                })
        time.sleep(1)  # Be polite to LeetCode and Gemini

    # Save visited problems to visited_problems.json as {slug: [languages]}
    with open(visited_json_path, "w", encoding="utf-8") as f:
        json.dump(visited, f, indent=2)

    # Create topic folders and problems.json
    for tslug, problems in topic_map.items():
        topic_folder = f"topics/{tslug}"
        os.makedirs(topic_folder, exist_ok=True)
        # Sort problems by number
        problems_sorted = sorted(problems, key=lambda x: int(x['number']))
        with open(os.path.join(topic_folder, "problems.json"), "w", encoding="utf-8") as f:
            json.dump(problems_sorted, f, indent=2)
        print(f"Created topic: {topic_folder} with {len(problems_sorted)} problems")

if __name__ == "__main__":
    main()
