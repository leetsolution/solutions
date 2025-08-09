import requests
import os

GEMINI_API_KEY = "AIzaSyAuVUbmH1H5csc7EjNiaXsqzaCNfW8s-kk"
if not GEMINI_API_KEY:
    GEMINI_API_KEY = input("Enter your Gemini API key: ").strip()
GEMINI_API_URL = "https://generativelanguage.googleapis.com/v1/models/gemini-1.5-pro:generateContent"


# Example LeetCode problem (Earliest Finish Time for Land and Water Rides II)
problem_title = "Earliest Finish Time for Land and Water Rides II"
# Minimal problem statement, constraints, and one example
problem_content = (
    "You are given two categories of theme park attractions: land rides and water rides. "
    "Each ride has a start time and a duration. "
    "A tourist must experience exactly one ride from each category, in either order. "
    "A ride may be started at its opening time or any later moment. "
    "If a ride is started at time t, it finishes at time t + duration. "
    "Immediately after finishing one ride the tourist may board the other (if it is already open) or wait until it opens. "
    "Return the earliest possible time at which the tourist can finish both rides.\n"
    "Constraints:\n"
    "1 <= n, m <= 5 * 10^4\n"
    "landStartTime.length == landDuration.length == n\n"
    "waterStartTime.length == waterDuration.length == m\n"
    "1 <= landStartTime[i], landDuration[i], waterStartTime[j], waterDuration[j] <= 10^5\n"
    "Example:\n"
    "Input: landStartTime = [2,8], landDuration = [4,1], waterStartTime = [6], waterDuration = [3]\n"
    "Output: 9"
)
language = "python3"
prompt = f"Solve the following LeetCode problem in {language}:\nTitle: {problem_title}\n\nDescription:\n{problem_content}\n\nProvide only the code."
print("Prompt sent to Gemini 2.5 Pro:\n")
print(prompt)
payload = {
    "contents": [{"parts": [{"text": prompt}]}]
}
params = {"key": GEMINI_API_KEY}

try:
    response = requests.post(GEMINI_API_URL, params=params, json=payload, timeout=1000) # Increased timeout
    response.raise_for_status()
    result = response.json()
    print("Raw Gemini 2.5 Pro response:")
    print(result)
    # Try to extract code if present
    if ('candidates' in result and
            'content' in result['candidates'][0] and
            'parts' in result['candidates'][0]['content'] and
            result['candidates'][0]['content']['parts'][0]['text']):
        print("\nExtracted code:")
        print(result['candidates'][0]['content']['parts'][0]['text'])
    else:
        print("No code or text found in response.")
except Exception as e:
    print("Error communicating with Gemini 2.5 Pro:", e)
