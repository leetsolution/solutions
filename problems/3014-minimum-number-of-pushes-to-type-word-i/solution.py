class Solution:
    def minimumPushes(self, word: str) -> int:
        counts = {}
        for char in word:
            counts[char] = counts.get(char, 0) + 1

        sorted_counts = sorted(counts.values(), reverse=True)
        
        pushes = 0
        for i in range(len(sorted_counts)):
            if i < 8:
                pushes += sorted_counts[i]
            elif i < 16:
                pushes += 2 * sorted_counts[i]
            elif i < 24:
                pushes += 3 * sorted_counts[i]
            else:
                pushes += 4 * sorted_counts[i]
        
        return pushes