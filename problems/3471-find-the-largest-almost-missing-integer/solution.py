class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        n = len(nums)
        counts = {}
        for i in range(n - k + 1):
            sub_array = nums[i:i+k]
            for num in sub_array:
                if num not in counts:
                    counts[num] = 0
                counts[num] += 1

        almost_missing = []
        for num, count in counts.items():
            if count == 1:
                almost_missing.append(num)

        if not almost_missing:
            return -1
        else:
            return max(almost_missing)