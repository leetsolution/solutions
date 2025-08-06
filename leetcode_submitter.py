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

LEETCODE_USERNAME = "msaswata15gdsc@gmail.com"
LEETCODE_PASSWORD = ".sEP/7F!d%V(R7x"

CHROMEDRIVER_PATH = r"D:\DOWNLOADS\chromedriver-win64 (1)\chromedriver-win64\chromedriver.exe"  # full path to chromedriver.exe

# Use your LEETCODE_SESSION cookie here
LEETCODE_SESSION = "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJfYXV0aF91c2VyX2lkIjoiMTg2NTg1MzAiLCJfYXV0aF91c2VyX2JhY2tlbmQiOiJhbGxhdXRoLmFjY291bnQuYXV0aF9iYWNrZW5kcy5BdXRoZW50aWNhdGlvbkJhY2tlbmQiLCJfYXV0aF91c2VyX2hhc2giOiI4MWUyY2Q3Y2IxMWE0NjZjNWIzODdjMmUxNmQ3MmY4ZjVlYTg4MTY2MjA4NzgxMzE1MDUyZGFiNjVkNDhjN2JlIiwic2Vzc2lvbl91dWlkIjoiN2I1NDUzMDAiLCJpZCI6MTg2NTg1MzAsImVtYWlsIjoibXNhc3dhdGExNWdkc2NAZ21haWwuY29tIiwidXNlcm5hbWUiOiJLREY3SlFldFhBIiwidXNlcl9zbHVnIjoiS0RGN0pRZXRYQSIsImF2YXRhciI6Imh0dHBzOi8vYXNzZXRzLmxlZXRjb2RlLmNvbS91c2Vycy9LREY3SlFldFhBL2F2YXRhcl8xNzU0MjM2NjQyLnBuZyIsInJlZnJlc2hlZF9hdCI6MTc1NDI4ODg5NiwiaXAiOiIyNDA1OjIwMTo5MDBmOjE4ZTU6OTUxOTo2YTQ2OmMyOWM6MmE0ZiIsImlkZW50aXR5IjoiN2RkZWRhODhkMGM1OTljYzQ5NGRhMGRlY2U2NTU0ZDUiLCJkZXZpY2Vfd2l0aF9pcCI6WyI2Y2U1NDM2MjM1ODgwZGU4NDAwZTExOWFlNTA3YWMwYyIsIjI0MDU6MjAxOjkwMGY6MThlNTo5NTE5OjZhNDY6YzI5YzoyYTRmIl19.2HJoXCRA3YMYMN-Mf2AnKhqbHF4a8fGrU-WTxCJxwBI"

# Set to False to see browser, True for headless
HEADLESS = False

def submit_to_leetcode(driver, problem_slug, code, language="Java"):
    # Go to LeetCode problem page
    driver.get(f"https://leetcode.com/problems/{problem_slug}/")
    time.sleep(3)
    # Check for 'Page Not Found' or 404
    page_source = driver.page_source
    if ("Page Not Found" in page_source) or ("404" in page_source):
        print(f"[WARN] Problem page not found for slug: {problem_slug}. Skipping.")
        return "__PAGE_NOT_FOUND__"
    # Helper to dismiss overlays
    from selenium.webdriver.common.action_chains import ActionChains
    def dismiss_overlays():
        try:
            ActionChains(driver).send_keys(Keys.ESCAPE).perform()
            time.sleep(0.3)
        except Exception:
            pass
    # Language selection and overlays first, then paste code
    lang_selected = False
    try:
        # Always select the first language dropdown button (aria-haspopup='dialog') inside the code area
        # Find all buttons with aria-haspopup='dialog' and pick the one whose text matches a known language
        known_languages = ["Java", "C++", "Python", "C#", "JavaScript", "Go", "Rust", "Kotlin", "TypeScript", "Ruby", "Swift"]
        lang_buttons = driver.find_elements(By.XPATH, "//button[@aria-haspopup='dialog']")
        lang_dropdown_btn = None
        for btn in lang_buttons:
            btn_text = btn.text.strip()
            if btn_text in known_languages:
                lang_dropdown_btn = btn
                break
        if not lang_dropdown_btn:
            print("[DEBUG] No language dropdown button found. Available buttons:")
            for btn in lang_buttons:
                print(f"[DEBUG] - '{btn.text}'")
            raise Exception("No language dropdown button with known language text found.")
        print(f"[DEBUG] Found language dropdown button with text: '{lang_dropdown_btn.text}'")
        dismiss_overlays()
        lang_dropdown_btn.click()
        # Wait for the popover to appear
        from selenium.webdriver.common.by import By as SeleniumBy
        import selenium.common.exceptions
        import sys
        import traceback
        time.sleep(1.2)
        lang_selected = False
        try:
            # Find the open popover with role=dialog and data-state=open
            popovers = driver.find_elements(By.XPATH, "//div[@role='dialog' and @data-state='open']")
            if not popovers:
                print("[DEBUG] No open popover found after clicking language dropdown.")
                raise Exception("No open popover found.")
            popover = popovers[-1]  # Use the last one in case of multiple
            group_divs = popover.find_elements(By.XPATH, ".//div[contains(@class, 'group')]")
            java_div = None
            for group in group_divs:
                try:
                    text_div = group.find_element(By.XPATH, ".//div[contains(@class, 'text-text-primary')]")
                    if text_div.text.strip() == language:
                        java_div = group
                        break
                except selenium.common.exceptions.NoSuchElementException:
                    continue
            if java_div:
                print(f"[DEBUG] Found and will click language group div with text: '{language}'")
                java_div.click()
                lang_selected = True
            else:
                print("[DEBUG] Could not find group div with text '" + language + "' in popover.")
                for group in group_divs:
                    try:
                        text_div = group.find_element(By.XPATH, ".//div[contains(@class, 'text-text-primary')]")
                        print(f"[DEBUG] - '{text_div.text.strip()}'")
                    except Exception:
                        continue
                raise Exception(f"No group div with text '{language}' found in popover.")
        except Exception as e:
            print(f"[DEBUG] Exception in popover language selection: {e}")
            traceback.print_exc(file=sys.stdout)
    except Exception as e:
        print(f"[DEBUG] Language dropdown selection failed: {e}")
        try:
            # Try old UI: direct span
            lang_button = WebDriverWait(driver, 10).until(
                EC.element_to_be_clickable((By.XPATH, f"//span[text()='{language}']"))
            )
            lang_button.click()
            lang_selected = True
        except Exception as e:
            print(f"Could not select language '{language}': {e}")
    if not lang_selected:
        print(f"Language '{language}' not found or not selectable. Skipping this problem.")
        driver.quit()
        return f"Language '{language}' not found."
    time.sleep(1)
    # Dismiss overlays before pasting code
    dismiss_overlays()
    # Now paste code
    # Paste code as-is
    code_to_paste = code.rstrip()
    try:
        textarea = driver.find_element(By.XPATH, "//textarea[@role='textbox' and contains(@class, 'inputarea')]")
        textarea.click()
        # Select all and delete to clear
        textarea.send_keys(Keys.CONTROL, 'a')
        textarea.send_keys(Keys.DELETE)
        # Send code from local file (with last bracket removed)
        textarea.send_keys(code_to_paste)
        time.sleep(1)
    except Exception as e2:
        print(f"[ERROR] Could not paste code in textarea: {e2}")
        raise Exception("No code editor found on the page.")

    # Click submit button
    try:
        submit_btn = driver.find_element(By.XPATH, "//button[contains(., 'Submit')]")
        submit_btn.click()
        time.sleep(10)  # Wait for result
        # Try to get result from data-e2e-locator first
        result = None
        try:
            result_elem = driver.find_element(By.XPATH, "//span[@data-e2e-locator='submission-result']")
            result = result_elem.text.strip()
        except Exception:
            pass
        # Fallback to old method if not found
        if not result:
            try:
                result_elem = driver.find_element(By.CLASS_NAME, "result__3aF_")
                result = result_elem.text.strip() if result_elem else None
            except Exception:
                result = None
        print("Submission result:", result)
        return result
    except Exception as e:
        print(f"[ERROR] Could not submit or read result: {e}")
        return None

if __name__ == "__main__":
    # Batch submit all Java solutions in problems/ directory
    problems_dir = "problems"
    options = Options()
    if HEADLESS:
        options.add_argument('--headless')
    service = Service(CHROMEDRIVER_PATH)
    driver = webdriver.Chrome(service=service, options=options)
    # Go to LeetCode home page and set session cookie
    driver.get("https://leetcode.com")
    time.sleep(2)
    driver.add_cookie({
        'name': 'LEETCODE_SESSION',
        'value': LEETCODE_SESSION,
        'domain': '.leetcode.com',
        'path': '/',
        'secure': True,
        'httpOnly': True
    })
    driver.get("https://leetcode.com")
    time.sleep(2)
    try:
        driver.find_element(By.XPATH, "//img[contains(@src, 'avatar') or contains(@class, 'nav-user-avatar')]")
        print("Login successful: profile icon found.")
    except Exception:
        print("Warning: Not logged in. Check your LEETCODE_SESSION cookie value.")

    # Load accepted_solutions.json if it exists
    import json
    accepted_json = "accepted_solutions.json"
    if os.path.exists(accepted_json):
        with open(accepted_json, "r", encoding="utf-8") as jf:
            accepted_data = json.load(jf)
    else:
        accepted_data = {}

    # Load visited_problems.json if it exists
    visited_json = "visited_problems.json"
    if os.path.exists(visited_json):
        with open(visited_json, "r", encoding="utf-8") as vf:
            visited_data = set(json.load(vf))
    else:
        visited_data = set()

    for folder in os.listdir(problems_dir):
        folder_path = os.path.join(problems_dir, folder)
        if not os.path.isdir(folder_path):
            continue
        solution_path = os.path.join(folder_path, "solution.java")
        if not os.path.exists(solution_path):
            continue
        problem_slug = "-".join(folder.split("-")[1:])
        # Skip if already accepted
        if problem_slug in accepted_data:
            print(f"[INFO] Skipping {problem_slug} (already accepted)")
            continue
        while True:
            with open(solution_path, "r", encoding="utf-8") as f:
                code = f.read()
            print(f"Submitting {problem_slug}...")
            try:
                result = submit_to_leetcode(driver, problem_slug, code, language="Java")
                print(f"Result for {problem_slug}: {result}")
                if result == "__PAGE_NOT_FOUND__":
                    print(f"[INFO] Skipping {problem_slug} due to missing page.")
                    break
                # Mark as visited only after a submission attempt (not before skipping)
                visited_data.add(problem_slug)
                with open(visited_json, "w", encoding="utf-8") as vf:
                    json.dump(sorted(list(visited_data)), vf, indent=2)
                if result == "__SAVE_CODE__" or (result and "Accepted" in result):
                    # Save the code from local file to accepted_solutions.json
                    try:
                        # Read code from local file
                        with open(solution_path, "r", encoding="utf-8") as f:
                            correct_code = f.read()
                        accepted_data[problem_slug] = correct_code
                        with open(accepted_json, "w", encoding="utf-8") as jf:
                            json.dump(accepted_data, jf, indent=2)
                        print(f"[INFO] Saved accepted solution for {problem_slug} to {accepted_json}")
                    except Exception as e:
                        print("[WARN] Could not save accepted solution to JSON:", e)
                    break
                print("Waiting for you to update the solution.java file after Copilot Chat fix. Press Enter to retry...")
                input()
            except Exception as e:
                print(f"Error submitting {problem_slug}: {e}")
                print("Waiting for you to fix the error and press Enter to retry...")
                input()
    driver.quit()
