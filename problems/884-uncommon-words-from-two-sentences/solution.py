class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        count = {}
        for word in s1.split():
            count[word] = count.get(word, 0) + 1
        for word in s2.split():
            count[word] = count.get(word, 0) + 1
        result = []
        for word, freq in count.items():
            if freq == 1:
                result.append(word)
        return result