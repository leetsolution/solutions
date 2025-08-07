class Solution:
    def possibleStringCount(self, word: str) -> int:
        n = len(word)
        count = 1
        i = 0
        while i < n:
            j = i
            while j < n and word[i] == word[j]:
                j += 1
            if j - i > 1:
                count += j - i - 1
            i = j
        return count