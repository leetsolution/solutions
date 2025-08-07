class Solution:
    def maxFreqSum(self, s: str) -> int:
        vowels = "aeiou"
        vowel_counts = {}
        consonant_counts = {}

        for char in s:
            if char in vowels:
                vowel_counts[char] = vowel_counts.get(char, 0) + 1
            else:
                consonant_counts[char] = consonant_counts.get(char, 0) + 1

        max_vowel_freq = 0
        if vowel_counts:
            max_vowel_freq = max(vowel_counts.values())

        max_consonant_freq = 0
        if consonant_counts:
            max_consonant_freq = max(consonant_counts.values())

        return max_vowel_freq + max_consonant_freq