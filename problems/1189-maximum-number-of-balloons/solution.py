class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        counts = {}
        for char in text:
            counts[char] = counts.get(char, 0) + 1

        balloon_counts = {'b': 0, 'a': 0, 'l': 0, 'o': 0, 'n': 0}

        for char in balloon_counts:
            if char in counts:
                balloon_counts[char] = counts[char]
            else:
                return 0

        min_balloons = float('inf')
        min_balloons = min(min_balloons, balloon_counts['b'])
        min_balloons = min(min_balloons, balloon_counts['a'])
        min_balloons = min(min_balloons, balloon_counts['n'])
        min_balloons = min(min_balloons, balloon_counts['l'] // 2)
        min_balloons = min(min_balloons, balloon_counts['o'] // 2)

        return min_balloons