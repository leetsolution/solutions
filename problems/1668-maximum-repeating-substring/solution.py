class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        k = 0
        while True:
            repeating_word = word * (k + 1)
            if repeating_word in sequence:
                k += 1
            else:
                return k