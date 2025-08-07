class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        result = []
        remaining = []
        counts = {}
        for num in arr1:
            if num in counts:
                counts[num] += 1
            else:
                counts[num] = 1
        for num in arr2:
            if num in counts:
                result.extend([num] * counts[num])
                del counts[num]
        for num in counts:
            remaining.extend([num] * counts[num])
        remaining.sort()
        return result + remaining