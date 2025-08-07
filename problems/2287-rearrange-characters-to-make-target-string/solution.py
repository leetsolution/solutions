class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        s_counts = {}
        target_counts = {}
        for char in s:
            s_counts[char] = s_counts.get(char, 0) + 1
        for char in target:
            target_counts[char] = target_counts.get(char, 0) + 1

        ans = float('inf')
        for char, count in target_counts.items():
            if char not in s_counts:
                return 0
            ans = min(ans, s_counts[char] // count)

        return ans