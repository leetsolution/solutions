class Solution:
    def sortSentence(self, s: str) -> str:
        words = s.split()
        sorted_words = sorted(words, key=lambda x: int(x[-1]))
        result = [word[:-1] for word in sorted_words]
        return " ".join(result)