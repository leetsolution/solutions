import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import json

# --- User must provide their cookies as a list of dicts (see below) ---
CHATGPT_COOKIES = [
    {
        "domain": ".chatgpt.com",
        "expirationDate": 1762258558.773841,
        "hostOnly": False,
        "httpOnly": True,
        "name": "__Secure-next-auth.session-token",
        "path": "/",
        "sameSite": "lax",
        "secure": True,
        "session": False,
        "storeId": None,
        "value": "eyJhbGciOiJkaXIiLCJlbmMiOiJBMjU2R0NNIn0..5NesBv6F4x7E2iNZ.vRuGYJwfZtsAvcQZxgsiyd-2nWSErM3QmEuq_LpHXDT_WRU8qiLZfTIUr5FtS5n90fxc9iYaIfAF65DnXv1oBTbWDJjVOqGo_cFw5xIdljd0W9kFZl1UAvOK5n_fd1DLuZKq1GcvWiLNI0a4xug965H6td8_rGFrW-d1s32jq4I4ClID0PaEfTTaLKeFRM6fOdCpd5bPx3J-B5pPWvN6L3_JBEvrYz8K5GJBrKeTzST0-Wp-KWf8cUbMHxEPQfK6N4HAwaAddeZ_S79FGFFy_3qTBgZcshyg5QsvZO8hTAO3y_eeGemDVP6fObnXfMNYdci6CYhxmBhr3m0TKo7LeIfhAGKzpSrXy-WL3oBPz81PBGym-1zPi6QOAFttqedxPzyb3o5TnkdAJcU8OlSDFploz10U_y_PBLd5HA2XSfBO7R2N7EnfYnnSc__KbJHp3oPCAY-hGSULbS_p4E7M0Py_kypHWA3pjcZQZrlJf9L3f69kniUEZPQYcsrYIYXy-6AqfEpsZXINc1n0Vr90ahlWTmAizkZut2z-uUFIGca196s3LqCB4ErLrtxu4bC65g_Qf1e731_cY79OlW4XWfMuSauBBEb-2u-gM1sZPecwTU0D7ks7QPhQDrH8xUaGp1nHbtOBiWk3JUUhRO66XO44vXQfq86S90Lmi4rkFKBo5EqXi8iTgfB4cgzeV9YLHDM2Xnl9SaDqaNCXe5HZs-_0P1ULaWDnaQC2kPrBMw3LH9SYJiUFRP8e5EBM52Vj4T8di3SeL3HqJUBC9ZdYthR1swoTxH3e6A-tLN6EUONC3bpiq6bVo9VF0cH0vjyGxIMgEAEUeklX5xIOaugaxpv47q3hGyeRWRko7PbKYGbPyCxmzv2sJSk2fTquKFY7s5HjwkpzKGwVKOj4hofhBKUzC9l0xRQS9K8b9sHWWx-4z5VXWABT4_ehc9oLRRax3p6XbfADME0nRDlnhYO8YfxqzYoQkEF6gkS6tJJH8xg_BWJurbMAg6Vy_uOhfxUG3u3Edc8sMy1kHAnQbpI5YwpeXhV1KH5EL4Usqhw44G4FdWNLd6ykCw52VR4SF1suabZoKSbrI-q4jVSAd0u6ywSp3ijOo7ZrlS2UCd9A0ouGf0TQYJXL1qF28isP5VFaA7AXTNuobhDVzu0DDht55oxgo_AJx6T0qq0EkBfMt_BQVBXeiW7BK5i-NfsJC9dCn-oJ0QjSaBRgb85jI4Fimr-OGch9HIriPygnIk2IFOwsAaoFQsT2SZS8VvUNusSPCUqYAWvkKZBpf6VTnD4VJgPQzdf3AqrAmH10U8hSKCz1SKQhPPJwXUwJvzVne-P7YqsY9KJJF6QoqeHsEUu2OnJzTIXPkYB3tDE8FIYEgC7zlqcH9Gm1oAAnPaiTtoA1JKMda2l221obxYtrx4BGZuFx0CdRSqXENkR7tvi_Su-fTmnUZfvvGFsKiy_bhqHXo2ZVe-5Oqn_HdwifTQIwJQAv1IDqKH2XRFDEgUFugaLMaXrXes7PZM0Yr-mvIWOg6zys1q0_itIo0NBnm_IRNzefoYM3aDfwDeKD3DZaZXC8-jSvzl8RB9HlrRvGR1yomzw9BKsDS-uwUTFOMWmkzPIIJq2IqHvbFsCdhGlef7XfKEwUy1RiE1YYPFzsdTB7y2__QKZqZI9hLvVR1zCfRi8hGFrq7Qqt-8rBTsc3Gkaxcl2F_qLM9w-FOSaVAACxzZc-LFa0OHWnLjngjw_7-d78mtVZSKCerDdOSG7n0cxSt0UjXTaIKu-aage3HU9QNctvKGc-BL3nUsWLxB-Dm1hCL5EkmYqQktx_32sceEavIm6KKItGtq0hfHRC82YpgwVwP8tL_Ikpvd9gN6_Mo3hLrZXKkYwK1cLTYPvPWUqF6XJdIUqQMMOQekvBtPM5k9GYR6Sj5x9FyB49BE5vFRIX3jK2yThqUMKyPJQmpnmwyN4jNZXTEfhhmuq82VQ5HdkCjBK8Fd3z3JU8FnhUB2MQB4evypxP43rmGteBsw_04i2qqoiruX5VNZiE2Hj74E84oO-9CWAjFPcu7QP3He7w5QvQUmNK6WH_-T80DzcglXUInDpZ-dajKJCreThu6JQKQK35SDCK2GV8ntIagCB7G62vzUvaVASJNMezX4uQwtsmAXHJXFhcpoGUnEjvtSlWdPEA3NPgiWkTnTpgvdhW8fJONgj6WSgrLSp4e_gNrAlxbQY4TLCVaOT21D8DOILXfAoGD3bFA9WNlBAo0y-qtrvkm0RCvbrNzrZz_VNCGVILVwgyyy9DVpx51rdJ0KV9kDjZjwe5kO1s62b4ZJ9ZSszn14QUI85_1BIbnbEsR-f_1gbPnmd9A72oNKQgFODt8pD0ty17GqaU-3sha62MvMFVTh6oviQOXUQpOWZu79g26Jg6YTyPr52nVt2aXzwdGE6RYJaOJ0k0xAGwxYWhuhbkd8oKZrp-UL3MFlGDt_2YMrDIZEcSP1mrLknASTtx9ZxhzX9p0DaITW_nzj59e0HdrfBFlly2IP8mNOIidhD6wy6jHTlXPjvVqszQja3E_gZelnU8KXjVmt3ORSHDBA-IlqMq-DUNvPEgQJTYtbqVYvPoSGGaWch5SEet10SF_k7wuW9jOX5-CQkQ0_DcQl8H1edHo8VRzlQGFs8Dn-f7aFbo69MQeAzp3tf9-s9hsxhm2fqGOP0vwkk180SoSOB50oY8ZYZqaZwyMLW9ihFewWfVaoKXmBi2YYxym2I3IEr0yv44n67S3p41KzNDlynbT8GMibKFHwU1VGPyjwCFanh6947ZwFxwQCZl8-lonJNV47efqxOGpiVysJV-gnmZa6YBnfQWbZh2gUX06H1xZaqpXA_1LUcKU5O4X4GchfpcHnQr8nT6PDdemPlS5Dka3GuET1n8p4ejcy1PP8rWXgmwhbW2azgay5ObY48zFqyvQVQWABA8AfDAXfr3cM8_SGIE5TRPln_ojw1SQVfwmRzfacOpBO4rvDMKXuo4JVN1DEdfTEkxPnSqS9XmxmtP11-Cpc5iTLFw0btSILUrWiMxS5Xo6mign5Cx5Z_HaO1LJz8hjJ5ZAO8cWGfXUUnFFQZP2sFURaXRTkvN17HQIPGgeavP3naSBqK2Ugeeo8hwUqG-pmfVG1-ScdZxealP6r33DKzX76BZCcZznpTu5DuoPI-lmB94oRMqi2B2GT0RebVanAlmHeqnBgwwzKv85hsJAJL-wuFuqkwrvrSdip4_jxzqdsCr2oa88d3zqyc6oTejZM4YjfEzk6KSKGe54xMN6uiNOXXgwUlYkn4L3eiSyXEeDwd8d7NarBVF2el6NJ25eyLCx6TE0c9N2LDPYCLINKlNbN_kNqwtgUqAJcCVNTrAR1taXvEWwN73sO4WoHqDL_EkLTV9Re_7vmHLMnrA2gv_xXeqsCzjvup0Q41gFTGclLyExAP1tDEZIbOcwU45WA5i5b7QY3g5eYDqwF44J3I.IOW0_lMFuRjPnPaqO2It6w"
    },
    {
        "domain": "chatgpt.com",
        "expirationDate": 1754486158.774155,
        "hostOnly": True,
        "httpOnly": True,
        "name": "__cflb",
        "path": "/",
        "sameSite": "no_restriction",
        "secure": True,
        "session": False,
        "storeId": None,
        "value": "0H28vzvP5FJafnkHxj4UVEnT813iA2wJYWmXkJs11jR"
    },
    {
        "domain": "chatgpt.com",
        "expirationDate": 1768801170.622212,
        "hostOnly": True,
        "httpOnly": False,
        "name": "oai-hlib",
        "path": "/",
        "sameSite": "lax",
        "secure": False,
        "session": False,
        "storeId": None,
        "value": "true"
    },
    {
        "domain": ".chatgpt.com",
        "expirationDate": 1754892270.311034,
        "hostOnly": False,
        "httpOnly": False,
        "name": "oai_consent_marketing",
        "path": "/",
        "sameSite": "lax",
        "secure": False,
        "session": False,
        "storeId": None,
        "value": "false"
    },
    {
        "domain": "chatgpt.com",
        "hostOnly": True,
        "httpOnly": False,
        "name": "oai_consent_analytics",
        "path": "/",
        "sameSite": None,
        "secure": False,
        "session": True,
        "storeId": None,
        "value": "false"
    },
    {
        "domain": "chatgpt.com",
        "expirationDate": 1754483669,
        "hostOnly": True,
        "httpOnly": False,
        "name": "_dd_s",
        "path": "/",
        "sameSite": "strict",
        "secure": False,
        "session": False,
        "storeId": None,
        "value": "rum=0&expire=1754483666639&logs=1&id=d5768865-4f48-47b4-ab12-8e40ab923811&created=1754482559728"
    },
    {
        "domain": ".chatgpt.com",
        "expirationDate": 1754892270.31079,
        "hostOnly": False,
        "httpOnly": False,
        "name": "oai_consent_analytics",
        "path": "/",
        "sameSite": "lax",
        "secure": False,
        "session": False,
        "storeId": None,
        "value": "false"
    },
    {
        "domain": ".chatgpt.com",
        "expirationDate": 1754484358.774059,
        "hostOnly": False,
        "httpOnly": True,
        "name": "__cf_bm",
        "path": "/",
        "sameSite": "no_restriction",
        "secure": True,
        "session": False,
        "storeId": None,
        "value": "EUV_zHjcv1LJ.R0XHM.__ggmRmJwwa19HvBcy.mdHEw-1754482567-1.0.1.1-yFNlhrTObIdQWtmg_yNyo0xbyeFJRK_HiFQSSHVobPeulPjvvkI41piJjTFZ2B1BilAJgtbj6xfmmVMmei0TTjVrPgv7MsQINeY9RptUCeA"
    },
    {
        "domain": "chatgpt.com",
        "hostOnly": True,
        "httpOnly": False,
        "name": "oai-hm",
        "path": "/",
        "sameSite": "lax",
        "secure": False,
        "session": True,
        "storeId": None,
        "value": "SHOULD_WE_BEGIN%20%7C%20AGENDA_TODAY"
    },
    {
        "domain": ".chatgpt.com",
        "hostOnly": False,
        "httpOnly": True,
        "name": "_cfuvid",
        "path": "/",
        "sameSite": "no_restriction",
        "secure": True,
        "session": True,
        "storeId": None,
        "value": "ogU5a1_us6N05zgZ50_uZJS1eL3BLQwb02gvrWq4wuk-1754446264403-0.0.1.1-604800000"
    },
    {
        "domain": ".chatgpt.com",
        "expirationDate": 1770034561.337114,
        "hostOnly": False,
        "httpOnly": False,
        "name": "oai-sc",
        "path": "/",
        "sameSite": "no_restriction",
        "secure": True,
        "session": False,
        "storeId": None,
        "value": "0gAAAAABok0eJ6TVU8ZAVqbVC3vOVmiru3lTnxpOTTua327y8rhozE2mpqimr9qCREjdjuWLf2oNECx6bgAZGl_VN6rjWdUtcsfqvoqPk0BaPizDbBnGmz3rR3m2dZixOkBkIuu9apudNGmm1437P3j0fj4NEw_3DloaepdZ7cSF4n4hnycpX9wAA6Jah7Vqer4xn2a-4Yu0Qo5bxupHiGRJ2jlzPkyLSd2ZqjMwzjWugLcmyiojA6qw"
    },
    {
        "domain": "chatgpt.com",
        "expirationDate": 1755017977.558346,
        "hostOnly": True,
        "httpOnly": False,
        "name": "oai-model-sticky-for-new-chats",
        "path": "/",
        "sameSite": "lax",
        "secure": False,
        "session": False,
        "storeId": None,
        "value": "false"
    },
    {
        "domain": "chatgpt.com",
        "hostOnly": True,
        "httpOnly": False,
        "name": "oai-gn",
        "path": "/",
        "sameSite": "lax",
        "secure": False,
        "session": True,
        "storeId": None,
        "value": ""
    },
    {
        "domain": "chatgpt.com",
        "expirationDate": 1755087360.169239,
        "hostOnly": True,
        "httpOnly": False,
        "name": "ext_name",
        "path": "/",
        "sameSite": None,
        "secure": False,
        "session": False,
        "storeId": None,
        "value": "ojplmecpdpgccookcobabopnaifgidhf"
    },
    {
        "domain": "chatgpt.com",
        "hostOnly": True,
        "httpOnly": True,
        "name": "__Host-next-auth.csrf-token",
        "path": "/",
        "sameSite": "lax",
        "secure": True,
        "session": True,
        "storeId": None,
        "value": "7dde652f55eac3701c32439e256e8926990a34dc1fe53ec82bd5b301758cea23%7C1f6f15be9587993ca9b701b5a7661ff1f402ae7aff9eb2cd074482e82416f502"
    },
    {
        "domain": "chatgpt.com",
        "hostOnly": True,
        "httpOnly": True,
        "name": "__Secure-next-auth.callback-url",
        "path": "/",
        "sameSite": "lax",
        "secure": True,
        "session": True,
        "storeId": None,
        "value": "https%3A%2F%2Fchatgpt.com"
    },
    {
        "domain": ".chatgpt.com",
        "expirationDate": 1754892270.311365,
        "hostOnly": False,
        "httpOnly": False,
        "name": "oai-allow-ne",
        "path": "/",
        "sameSite": "lax",
        "secure": False,
        "session": False,
        "storeId": None,
        "value": "false"
    },
    {
        "domain": ".chatgpt.com",
        "expirationDate": 1768495366.918064,
        "hostOnly": False,
        "httpOnly": False,
        "name": "oai-did",
        "path": "/",
        "sameSite": "lax",
        "secure": False,
        "session": False,
        "storeId": None,
        "value": "6e305b67-a60e-452e-bdf0-2ae68bed3885"
    },
    {
        "domain": "chatgpt.com",
        "expirationDate": 1754994922.835966,
        "hostOnly": True,
        "httpOnly": False,
        "name": "oai-nav-state",
        "path": "/",
        "sameSite": "lax",
        "secure": False,
        "session": False,
        "storeId": None,
        "value": "0"
    },
    {
        "domain": "chatgpt.com",
        "hostOnly": True,
        "httpOnly": False,
        "name": "oai_consent_marketing",
        "path": "/",
        "sameSite": None,
        "secure": False,
        "session": True,
        "storeId": None,
        "value": "false"
    }
]

CHATGPT_URL = "https://chatgpt.com/"
# Read prompt from external file if present, else use default
import os
DEFAULT_PROMPT = "Solve the following LeetCode problem in Python3.\nTitle: Two Sum\nDescription: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.\nStarter code:\ndef twoSum(nums, target):\n    # Your code here\n GIVE ONLY CODE NO CODE EXPLANATION OR COMMENTS\n    "
PROMPT = DEFAULT_PROMPT
if os.path.exists("chatgpt_prompt.txt"):
    with open("chatgpt_prompt.txt", "r", encoding="utf-8") as pf:
        PROMPT = pf.read()

# --- Selenium setup ---
def setup_driver():
    options = Options()
    options.add_argument('--disable-blink-features=AutomationControlled')
    options.add_argument('--start-maximized')
    # Uncomment below if you want to run headless
    # options.add_argument('--headless')
    service = Service(r"D:\DOWNLOADS\chromedriver-win64 (1)\chromedriver-win64\chromedriver.exe")
    driver = webdriver.Chrome(service=service, options=options)
    return driver

def inject_cookies(driver, cookies):
    driver.get(CHATGPT_URL)
    for cookie in cookies:
        c = cookie.copy()
        if 'expirationDate' in c:
            c['expiry'] = int(c['expirationDate'])
            del c['expirationDate']
        # Remove keys not accepted by Selenium
        for k in ['storeId', 'session']:
            c.pop(k, None)
        # Map sameSite to Selenium's expected values
        if 'sameSite' in c:
            ss = str(c['sameSite']).lower()
            if ss in ['strict', 'lax', 'none']:
                c['sameSite'] = ss.capitalize() if ss != 'none' else 'None'
            else:
                c.pop('sameSite')
        # Only set cookies for the current domain
        try:
            driver.add_cookie(c)
        except Exception as e:
            print(f"  Skipping cookie {c.get('name')}: {e}")
    driver.refresh()
    time.sleep(2)

def send_prompt(driver, prompt):
    # Try to paste into ProseMirror (contenteditable div) first
    try:
        input_box = None
        try:
            input_box = WebDriverWait(driver, 10).until(
                EC.presence_of_element_located((By.CSS_SELECTOR, "div.ProseMirror[contenteditable='true']"))
            )
            # Clear existing content
            input_box.click()
            input_box.send_keys(Keys.CONTROL + "a")
            input_box.send_keys(Keys.BACKSPACE)
            # Paste prompt
            for line in prompt.splitlines():
                input_box.send_keys(line)
                input_box.send_keys(Keys.SHIFT + Keys.ENTER)
            # Remove last shift-enter (extra newline)
            input_box.send_keys(Keys.BACKSPACE)
        except Exception:
            # Fallback to textarea
            input_box = WebDriverWait(driver, 20).until(
                EC.presence_of_element_located((By.TAG_NAME, "textarea"))
            )
            input_box.clear()
            input_box.send_keys(prompt)
        # Try to click the send button
        try:
            send_btn = driver.find_element(By.ID, "composer-submit-button")
            send_btn.click()
        except Exception:
            input_box.send_keys(Keys.ENTER)
        print("Prompt sent!")

        # Wait for Start voice mode button to appear (signals response is rendered)
        try:
            WebDriverWait(driver, 60).until(
                EC.presence_of_element_located((By.XPATH, "//button[@data-testid='composer-speech-button']"))
            )
            print("Start voice mode button appeared, scanning for response...")
            time.sleep(2)  # Give a moment for rendering
            # Re-locate the response container and code blocks to avoid stale reference
            response_containers = driver.find_elements(By.XPATH, "//div[contains(@class,'markdown')]")
            if response_containers:
                response_container = response_containers[-1]
                code_blocks = response_container.find_elements(By.XPATH, ".//pre/code")
                print(f"Found {len(code_blocks)} code block(s) in response.")
                if code_blocks:
                    with open("chatgpt_response.txt", "w", encoding="utf-8") as f:
                        for i, block in enumerate(code_blocks):
                            code_text = block.text
                            print(f"Extracted code block {i+1}:\n" + code_text)
                            f.write(code_text)
                            f.write("\n\n")
                    print("Saved all code blocks to chatgpt_response.txt.")
                else:
                    print("No code block found in response. Attempting to extract code from plain text...")
                    # Fallback: extract code from plain text
                    text = response_container.text
                    lines = text.splitlines()
                    code_lines = []
                    in_code = False
                    block_start = None
                    block_end = None
                    # Patterns for function/class start in Python, Java, C++, C
                    start_patterns = [
                        r'^def ',                # Python
                        r'^(public |private |protected )?class ', # Java/C++
                        r'^(public |private |protected )?(static )?(final )?[\w\<\>\[\]]+\s+[\w]+\s*\(', # Java/C++/C
                        r'^[\w\*\s]+\s+[\w]+\s*\(', # C/C++
                    ]
                    import re
                    for idx, line in enumerate(lines):
                        for pat in start_patterns:
                            if re.match(pat, line.strip()):
                                in_code = True
                                block_start = idx
                                break
                        if in_code:
                            break
                    if in_code and block_start is not None:
                        # For Python, grab indented lines; for others, grab until matching closing brace
                        first_line = lines[block_start]
                        code_lines.append(first_line)
                        # Python: indent-based
                        if first_line.strip().startswith('def '):
                            indent_level = len(first_line) - len(first_line.lstrip())
                            for line in lines[block_start+1:]:
                                if line.strip() == '' and code_lines:
                                    break
                                current_indent = len(line) - len(line.lstrip())
                                if line.strip() and current_indent < indent_level:
                                    break
                                if line.strip().startswith(('Explanation:', 'Example:', 'Copy', 'Edit', 'python')):
                                    break
                                code_lines.append(line)
                        else:
                            # Java/C++/C: brace-based
                            brace_count = 0
                            # Find first opening brace
                            found_brace = False
                            for line in lines[block_start+1:]:
                                if not found_brace:
                                    if '{' in line:
                                        found_brace = True
                                        brace_count += line.count('{')
                                        brace_count -= line.count('}')
                                        code_lines.append(line)
                                    continue
                                # After first brace, collect until braces are balanced
                                brace_count += line.count('{')
                                brace_count -= line.count('}')
                                code_lines.append(line)
                                if brace_count == 0 and found_brace:
                                    break
                                if line.strip().startswith(('Explanation:', 'Example:', 'Copy', 'Edit', 'python')):
                                    break
                        # Remove trailing empty lines
                        while code_lines and code_lines[-1].strip() == '':
                            code_lines.pop()
                    if code_lines:
                        code_text = '\n'.join(code_lines)
                        print("Extracted code from plain text:\n" + code_text)
                        with open("chatgpt_response.txt", "w", encoding="utf-8") as f:
                            f.write(code_text)
                        print("Saved extracted code to chatgpt_response.txt.")
                    else:
                        print("No code found in plain text response.")
            else:
                print("No markdown response container found.")
        except Exception as e:
            print(f"Error waiting for Start voice mode button or scraping response: {e}")
    except Exception as e:
        print(f"Error sending prompt: {e}")

def main():
    driver = setup_driver()
    inject_cookies(driver, CHATGPT_COOKIES)
    send_prompt(driver, PROMPT)
    # Wait for response (user can add logic to scrape output)
    time.sleep(30)
    driver.quit()

if __name__ == "__main__":
    main()
