class Solution:
    def mostVisited(self, n: int, rounds: List[int]) -> List[int]:
        counts = [0] * n
        start = rounds[0] - 1
        end = rounds[-1] - 1
        
        if start <= end:
            for i in range(start, end + 1):
                counts[i] += 1
        else:
            for i in range(start, n):
                counts[i] += 1
            for i in range(0, end + 1):
                counts[i] += 1
        
        max_count = 0
        for count in counts:
            max_count = max(max_count, count)
        
        result = []
        for i in range(n):
            if counts[i] == max_count:
                result.append(i + 1)
        
        return result