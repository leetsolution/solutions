class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        indices = [i for i, num in enumerate(nums) if num == key]
        result = set()
        for i in indices:
            for j in range(max(0, i - k), min(len(nums), i + k + 1)):
                result.add(j)
        return sorted(list(result))