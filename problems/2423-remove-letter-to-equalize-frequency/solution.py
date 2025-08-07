class Solution:
    def equalFrequency(self, word: str) -> bool:
        from collections import Counter
        count = Counter(word)
        for i in range(len(word)):
            temp_count = count.copy()
            char_to_remove = word[i]
            temp_count[char_to_remove] -= 1
            if temp_count[char_to_remove] == 0:
                del temp_count[char_to_remove]
            if not temp_count:
                return True
            frequencies = list(temp_count.values())
            if len(set(frequencies)) == 1:
                return True
        return False