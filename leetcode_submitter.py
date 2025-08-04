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
    try:
        textarea = driver.find_element(By.XPATH, "//textarea[@role='textbox' and contains(@class, 'inputarea')]")
        textarea.click()
        # Select all and delete to clear
        textarea.send_keys(Keys.CONTROL, 'a')
        textarea.send_keys(Keys.DELETE)
        # Send code from local file
        textarea.send_keys(code)
        time.sleep(1)
    except Exception as e2:
        print(f"[ERROR] Could not paste code in textarea: {e2}")
        raise Exception("No code editor found on the page.")
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
    # Debug print: show code being pasted
    print("[DEBUG] Code being pasted to LeetCode editor:\n" + code + "\n[END DEBUG CODE]\n")
    pasted = False
    try:
        code_mirror = driver.find_element(By.CLASS_NAME, "CodeMirror")
        code_mirror.click()
        time.sleep(1)
        js_code = f'''
        var editor = document.querySelector('.CodeMirror').CodeMirror;
        editor.setValue(`{code.replace('`', '\u0060')}`);
        '''
        driver.execute_script(js_code)
        pasted = True
        time.sleep(1)
    except Exception as e:
        print("[DEBUG] CodeMirror not found, trying textarea fallback.")
        try:
            textarea = driver.find_element(By.XPATH, "//textarea[@role='textbox' and contains(@class, 'inputarea')]")
            textarea.click()
            # Select all and delete to clear
            textarea.send_keys(Keys.CONTROL, 'a')
            textarea.send_keys(Keys.DELETE)
            # Always send code from local file
            textarea.send_keys(code)
            pasted = True
            time.sleep(1)
        except Exception as e2:
            print(f"[DEBUG] Could not paste code in textarea: {e2}")
    if not pasted:
        print("[ERROR] Could not find a code editor to paste the code.")
        raise Exception("No code editor found on the page.")
    # Click submit
    submit_btn = driver.find_element(By.XPATH, "//button[contains(., 'Submit')]" )
    submit_btn.click()
    time.sleep(10)  # Wait for result
    # Check result
    result = driver.find_element(By.CLASS_NAME, "result__3aF_" ).text
    print("Submission result:", result)
    # If not accepted, copy error and code to clipboard, open ChatGPT, and paste
    if "Accepted" not in result:
        try:
            import pyperclip
            error_message = f"LeetCode Submission Error for {problem_slug}:\n\nError Message:\n{result}\n\nSubmitted Code:\n{code}"
            pyperclip.copy(error_message)
            print("\n---\nError and code copied to clipboard. Opening ChatGPT in new tab...\n---\n")
            # Open ChatGPT in new tab
            driver.execute_script("window.open('https://chat.openai.com/', '_blank');")
            time.sleep(3)
            # Switch to ChatGPT tab
            driver.switch_to.window(driver.window_handles[-1])
            time.sleep(2)
            # Find textarea and paste error/code
            try:
                textarea = driver.find_element(By.TAG_NAME, "textarea")
                textarea.click()
                textarea.clear()
                textarea.send_keys(error_message)
                time.sleep(1)
                textarea.send_keys("\nPlease debug and fix the code for LeetCode submission.\n")
            except Exception as e:
                print("[DEBUG] Could not paste into ChatGPT textarea: ", e)
            print("\n---\nPlease review/fix in ChatGPT, copy the fixed code, then return to LeetCode tab.\n---\n")
            input("Press Enter after you have copied the fixed code from ChatGPT and are ready to paste it into LeetCode...")
            # Switch back to LeetCode tab
            driver.switch_to.window(driver.window_handles[0])
            time.sleep(1)
            # Remove previous code and paste new code
            dismiss_overlays()
            pasted = False
            try:
                code_mirror = driver.find_element(By.CLASS_NAME, "CodeMirror")
                code_mirror.click()
                time.sleep(1)
                # Select all and clear
                code_mirror.send_keys(Keys.CONTROL, 'a')
                code_mirror.send_keys(Keys.DELETE)
                # Always send code from local file
                js_code = f'''
                var editor = document.querySelector('.CodeMirror').CodeMirror;
                editor.setValue(`{code.replace('`', '\u0060')}`);
                '''
                driver.execute_script(js_code)
                pasted = True
                time.sleep(1)
            except Exception as e:
                print("[DEBUG] CodeMirror not found, trying textarea fallback.")
                try:
                    textarea = driver.find_element(By.XPATH, "//textarea[@role='textbox' and contains(@class, 'inputarea')]" )
                    textarea.click()
                    # Select all and delete to clear
                    textarea.send_keys(Keys.CONTROL, 'a')
                    textarea.send_keys(Keys.DELETE)
                    # Always send code from local file
                    textarea.send_keys(code)
                    pasted = True
                    time.sleep(1)
                except Exception as e2:
                    print(f"[DEBUG] Could not paste code in textarea: {e2}")
            if not pasted:
                print("[ERROR] Could not find a code editor to paste the code.")
                raise Exception("No code editor found on the page.")
            # Click submit
            submit_btn = driver.find_element(By.XPATH, "//button[contains(., 'Submit')]")
            submit_btn.click()
            time.sleep(10)
            # Check result
            result2 = driver.find_element(By.CLASS_NAME, "result__3aF_" ).text
            print("Submission result:", result2)
            if "Accepted" in result2:
                print("[INFO] Submission accepted. Saving code to local file.")
                return "__SAVE_CODE__"
            else:
                return result2
        except Exception as e:
            print("\n---\nCould not copy to clipboard or automate ChatGPT. Please do it manually.\n---\n")
            print(error_message)
            print("---\n")
            return result
    return result

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

    for folder in os.listdir(problems_dir):
        folder_path = os.path.join(problems_dir, folder)
        if not os.path.isdir(folder_path):
            continue
        solution_path = os.path.join(folder_path, "solution.java")
        if not os.path.exists(solution_path):
            continue
        problem_slug = "-".join(folder.split("-")[1:])
        while True:
            with open(solution_path, "r", encoding="utf-8") as f:
                code = f.read()
            print(f"Submitting {problem_slug}...")
            try:
                result = submit_to_leetcode(driver, problem_slug, code, language="Java")
                print(f"Result for {problem_slug}: {result}")
                if result == "__SAVE_CODE__" or ("Accepted" in result):
                    # Save the code from local file to accepted_solutions.json
                    try:
                        import json
                        accepted_json = "accepted_solutions.json"
                        # Read code from local file
                        with open(solution_path, "r", encoding="utf-8") as f:
                            correct_code = f.read()
                        # Load or create JSON
                        if os.path.exists(accepted_json):
                            with open(accepted_json, "r", encoding="utf-8") as jf:
                                data = json.load(jf)
                        else:
                            data = {}
                        data[problem_slug] = correct_code
                        with open(accepted_json, "w", encoding="utf-8") as jf:
                            json.dump(data, jf, indent=2)
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
