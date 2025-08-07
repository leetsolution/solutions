class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        result = []
        for word in words:
            if not result or sorted(result[-1]) != sorted(word):
                result.append(word)
        return result