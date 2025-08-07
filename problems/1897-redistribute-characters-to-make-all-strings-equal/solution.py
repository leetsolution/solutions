class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        counts = {}
        total_length = 0
        for word in words:
            total_length += len(word)
            for char in word:
                counts[char] = counts.get(char, 0) + 1
        for count in counts.values():
            if count % len(words) != 0:
                return False
        return True