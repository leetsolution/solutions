class Solution:
    def countVowelSubstrings(self, word: str) -> int:
        vowels = "aeiou"
        count = 0
        for i in range(len(word)):
            for j in range(i, len(word)):
                substring = word[i:j+1]
                is_vowel_substring = True
                vowel_set = set()
                for char in substring:
                    if char not in vowels:
                        is_vowel_substring = False
                        break
                    vowel_set.add(char)
                if is_vowel_substring and len(vowel_set) == 5:
                    count += 1
        return count