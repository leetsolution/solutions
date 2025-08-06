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
GEMINI_API_KEY = "AIzaSyBiUOhqwzZ_SG1hmB5FAFN-AEC_if4IIrE"
GEMINI_API_URL = "https://generativelanguage.googleapis.com/v1/models/gemini-1.5-flash:generateContent"

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

def generate_solution_with_gemini(problem_title, problem_content, language):
    prompt = f"""Solve the following LeetCode problem in {language}:
\nTitle: {problem_title}\n\nDescription:\n{problem_content}\n\nProvide only the code."""
    payload = {
        "contents": [{"parts": [{"text": prompt}]}]
    }
    params = {"key": GEMINI_API_KEY}
    try:
        response = requests.post(GEMINI_API_URL, params=params, json=payload, timeout=30)
        response.raise_for_status()
        result = response.json()
        return result['candidates'][0]['content']['parts'][0]['text']
    except Exception as e:
        print(f"  Gemini API error for {language}: {e}")
        return f"# Gemini did not return a valid solution for {problem_title} in {language}."
import os
import requests
import time


# LeetCode session cookie (provided by user)
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
    Insert Gemini's generated function/method body into the starter code.
    For Python, Java, C++, C: replace the method body with Gemini's code.
    Also removes markdown code block artifacts from Gemini output.
    """
    if not starter_code or not gemini_body:
        return starter_code or gemini_body or ''
    import re
    # Remove markdown code block artifacts
    gemini_body = re.sub(r'^```[a-zA-Z]*', '', gemini_body, flags=re.MULTILINE)
    gemini_body = re.sub(r'```$', '', gemini_body, flags=re.MULTILINE)
    gemini_body = gemini_body.strip()
    if lang == 'python3':
        lines = starter_code.splitlines()
        for i, line in enumerate(lines):
            if line.strip().endswith(':'):
                indent = len(line) - len(line.lstrip()) + 4
                gemini_lines = [" " * indent + l if l.strip() else '' for l in gemini_body.splitlines()]
                return '\n'.join(lines[:i+1] + gemini_lines)
        return starter_code + '\n' + gemini_body
    elif lang == 'java':
        m = re.search(r'(public .*\{)([\s\S]*)(\})', starter_code)
        if m:
            before = m.group(1)
            after = m.group(3)
            gemini_lines = ['    ' + l if l.strip() else '' for l in gemini_body.splitlines()]
            return starter_code[:m.start(1)] + before + '\n' + '\n'.join(gemini_lines) + '\n' + after + starter_code[m.end(3):]
        return starter_code + '\n' + gemini_body
    elif lang == 'cpp':
        m = re.search(r'(\)\s*\{)([\s\S]*)(\})', starter_code)
        if m:
            before = m.group(1)
            after = m.group(3)
            gemini_lines = ['    ' + l if l.strip() else '' for l in gemini_body.splitlines()]
            return starter_code[:m.start(1)] + before + '\n' + '\n'.join(gemini_lines) + '\n' + after + starter_code[m.end(3):]
        return starter_code + '\n' + gemini_body
    elif lang == 'c':
        m = re.search(r'(\)\s*\{)([\s\S]*)(\})', starter_code)
        if m:
            before = m.group(1)
            after = m.group(3)
            gemini_lines = ['    ' + l if l.strip() else '' for l in gemini_body.splitlines()]
            return starter_code[:m.start(1)] + before + '\n' + '\n'.join(gemini_lines) + '\n' + after + starter_code[m.end(3):]
        return starter_code + '\n' + gemini_body
    else:
        return starter_code + '\n' + gemini_body

def main():
    slugs = get_problem_slugs()
    topic_map = {}
    import random
    for slug in slugs:
        available_langs = get_available_languages(slug)
        # Skip if only SQL or unsupported languages are available
        if not any(lang in available_langs for lang in LANGUAGES.keys()):
            print(f"Skipping {slug}: only SQL or unsupported languages.")
            continue
        meta = get_problem_metadata(slug)
        number = meta['number']
        title = meta['title']
        content = meta['content']
        difficulty = meta['difficulty']
        topics = meta['topics']
        folder_name = f"problems/{str(number).zfill(3)}-{slugify_title(title)}"
        created_folder = False
        written_code = False
        import json
        from datetime import datetime, timezone
        for lang, filename in LANGUAGES.items():
            if lang not in available_langs:
                print(f"  Skipping {filename}: not available for this problem.")
                continue
            try:
                starter_code = get_starter_code(slug, lang)
                print(f"    Starter code for {lang}:\n{starter_code}\n---")
                # Always ask Gemini for a solution body
                gemini_body = generate_solution_with_gemini(title, content, lang)
                print(f"    Gemini code for {lang}:\n{gemini_body}\n---")
                # Only proceed if Gemini returned a valid response
                if gemini_body and gemini_body.strip() != '' and not gemini_body.strip().startswith('# Gemini did not return'):
                    if not created_folder:
                        os.makedirs(folder_name, exist_ok=True)
                        print(f"Processing {number}. {title} -> {folder_name}")
                        # Save README.md
                        with open(os.path.join(folder_name, "README.md"), "w", encoding="utf-8") as f:
                            f.write(f"# {number}. {title}\n\n## Problem Statement\n{content}\n\n## Difficulty\n{difficulty}\n\n## Topics\n{', '.join([t['name'] for t in topics])}\n")
                        print(f"  Wrote README.md")
                        # Save problem.json with all metadata
                        problem_data = {
                            "number": number,
                            "title": title,
                            "description": content,
                            "difficulty": difficulty,
                            "topics": [t['name'] for t in topics],
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
                    else:
                        print(f"  No code generated for {filename}.")
                else:
                    print(f"  No valid Gemini response for {filename}.")
                # Sleep 10-30 seconds to avoid Gemini API rate limits
                sleep_time = random.randint(10, 30)
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

    # Create topic folders and problems.json
    for tslug, problems in topic_map.items():
        topic_folder = f"topics/{tslug}"
        os.makedirs(topic_folder, exist_ok=True)
        # Sort problems by number
        problems_sorted = sorted(problems, key=lambda x: int(x['number']))
        import json
        with open(os.path.join(topic_folder, "problems.json"), "w", encoding="utf-8") as f:
            json.dump(problems_sorted, f, indent=2)
        print(f"Created topic: {topic_folder} with {len(problems_sorted)} problems")

if __name__ == "__main__":
    main()
