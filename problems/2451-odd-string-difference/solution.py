class Solution:
    def oddString(self, words: List[str]) -> str:
        diffs = []
        for word in words:
            diff = []
            for i in range(len(word) - 1):
                diff.append(ord(word[i+1]) - ord(word[i]))
            diffs.append(diff)

        counts = {}
        for i, diff in enumerate(diffs):
            diff_tuple = tuple(diff)
            if diff_tuple not in counts:
                counts[diff_tuple] = []
            counts[diff_tuple].append(i)

        for diff_tuple, indices in counts.items():
            if len(indices) == 1:
                return words[indices[0]]