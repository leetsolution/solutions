class Solution:
    def maximumNumberOfStringPairs(self, words: List[str]) -> int:
        count = 0
        seen = set()
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if words[i] == words[j][::-1]:
                    count += 1
                    break
        return count