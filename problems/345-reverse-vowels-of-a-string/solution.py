class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = "aeiouAEIOU"
        s_list = list(s)
        vowel_indices = [i for i, char in enumerate(s_list) if char in vowels]
        vowel_chars = [s_list[i] for i in vowel_indices]
        vowel_chars.reverse()
        for i, index in enumerate(vowel_indices):
            s_list[index] = vowel_chars[i]
        return "".join(s_list)