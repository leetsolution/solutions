class Solution:
    def greatestLetter(self, s: str) -> str:
        letters = set(s)
        for char_code in range(ord('Z'), ord('A') - 1, -1):
            char = chr(char_code)
            if char in letters and char.lower() in letters:
                return char
        return ""