class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if len(word) == 0:
            return True
        
        all_caps = word.isupper()
        no_caps = word.islower()
        first_cap = word[0].isupper() and word[1:].islower()

        return all_caps or no_caps or first_cap