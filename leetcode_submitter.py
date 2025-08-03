# LeetCode Submitter using Selenium
# Requirements: pip install selenium
# Download ChromeDriver and put it in your PATH or specify its location below

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.chrome.service import Service
import time
import os

LEETCODE_USERNAME = "YOUR_USERNAME"
LEETCODE_PASSWORD = "YOUR_PASSWORD"

CHROMEDRIVER_PATH = "chromedriver"  # or full path to chromedriver.exe

# Use your LEETCODE_SESSION cookie here
LEETCODE_SESSION = "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJhY2NvdW50X3ZlcmlmaWVkX2VtYWlsIjpudWxsLCJfYXV0aF91c2VyX2lkIjoiMTg2NTg1MzAiLCJfYXV0aF91c2VyX2JhY2tlbmQiOiJhbGxhdXRoLmFjY291bnQuYXV0aF9iYWNrZW5kcy5BdXRoZW50aWNhdGlvbkJhY2tlbmQiLCJfYXV0aF91c2VyX2hhc2giOiJmYzAxMTNmMjYyZjdkNTJhYjMwNmVhM2ZkYjhkOGVlNzMxYzYyYTQ1ZjYyZGU1MDk5ZWE3MmI2YjIwY2E0NGY2Iiwic2Vzc2lvbl91dWlkIjoiYTg5MDc3NjkiLCJpZCI6MTg2NTg1MzAsImVtYWlsIjoibXNhc3dhdGExNWdkc2NAZ21haWwuY29tIiwidXNlcm5hbWUiOiJLREY3SlFldFhBIiwidXNlcl9zbHVnIjoiS0RGN0pRZXRYQSIsImF2YXRhciI6Imh0dHBzOi8vYXNzZXRzLmxlZXRjb2RlLmNvbS91c2Vycy9kZWZhdWx0X2F2YXRhci5qcGciLCJyZWZyZXNoZWRfYXQiOjE3NTQyMzY2NDIsImlwIjoiMjQwNToyMDE6OTAwZjoxOGU1Ojk1NGY6MmEyZTpiYzo4MGNhIiwiaWRlbnRpdHkiOiI3ZGRlZGE4OGQwYzU5OWNjNDk0ZGEwZGVjZTY1NTRkNSIsImRldmljZV93aXRoX2lwIjpbIjUyMjg5MDFlYjAyOGFmZWQ3ODE5MWYyNjg4NGMyMTQ1IiwiMjQwNToyMDE6OTAwZjoxOGU1Ojk1NGY6MmEyZTpiYzo4MGNhIl19.3oPWKwIr-QfrPXq6O5ZynELtJ4eWoWTt4dbA_KXqMYY"

# Set to False to see browser, True for headless
HEADLESS = False

def submit_to_leetcode(problem_slug, code, language="Java"):
    options = Options()
    if HEADLESS:
        options.add_argument('--headless')
    service = Service(CHROMEDRIVER_PATH)
    driver = webdriver.Chrome(service=service, options=options)
    driver.get("https://leetcode.com")
    # Set LEETCODE_SESSION cookie for authentication
    driver.add_cookie({
        'name': 'LEETCODE_SESSION',
        'value': LEETCODE_SESSION,
        'domain': '.leetcode.com',
        'path': '/',
        'secure': True,
        'httpOnly': True
    })
    driver.refresh()
    time.sleep(2)
    # Go to problem
    driver.get(f"https://leetcode.com/problems/{problem_slug}/")
    time.sleep(3)
    # Select language
    lang_button = driver.find_element(By.XPATH, f"//span[text()='{language}']")
    lang_button.click()
    time.sleep(1)
    # Paste code
    code_mirror = driver.find_element(By.CLASS_NAME, "CodeMirror")
    code_mirror.click()
    time.sleep(1)
    # Clear existing code
    code_mirror.send_keys(Keys.CONTROL, "a")
    code_mirror.send_keys(Keys.DELETE)
    # Paste new code
    for line in code.splitlines():
        code_mirror.send_keys(line)
        code_mirror.send_keys(Keys.SHIFT, Keys.ENTER)
    time.sleep(1)
    # Click submit
    submit_btn = driver.find_element(By.XPATH, "//button[contains(., 'Submit')]" )
    submit_btn.click()
    time.sleep(10)  # Wait for result
    # Check result
    result = driver.find_element(By.CLASS_NAME, "result__3aF_" ).text
    print("Submission result:", result)
    driver.quit()
    return result

if __name__ == "__main__":
    # Batch submit all Java solutions in problems/ directory
    problems_dir = "problems"
    for folder in os.listdir(problems_dir):
        folder_path = os.path.join(problems_dir, folder)
        if not os.path.isdir(folder_path):
            continue
        solution_path = os.path.join(folder_path, "solution.java")
        if not os.path.exists(solution_path):
            continue
        problem_slug = folder
        with open(solution_path, "r", encoding="utf-8") as f:
            code = f.read()
        print(f"Submitting {problem_slug}...")
        try:
            result = submit_to_leetcode(problem_slug, code, language="Java")
            print(f"Result for {problem_slug}: {result}")
        except Exception as e:
            print(f"Error submitting {problem_slug}: {e}")
