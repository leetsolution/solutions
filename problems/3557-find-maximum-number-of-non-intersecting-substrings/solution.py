class Solution:
    def maxSubstrings(self, word: str) -> int:
        first = {}
        last = {}
        for i, c in enumerate(word):
            if c not in first:
                first[c] = i
            last[c] = i

        intervals = []
        for c in first:
            l, r = first[c], last[c]
            new_l = l
            i = l
            while i <= r:
                char = word[i]
                if first[char] < l:
                    new_l = first[char]
                    l = new_l
                    i = l
                    continue
                r = max(r, last[char])
                i += 1
            intervals.append((l, r))

        intervals.sort(key=lambda x: x[1])
        res = 0
        end = -1
        for l, r in intervals:
            if r - l + 1 >= 4 and l > end:
                res += 1
                end = r
        return res