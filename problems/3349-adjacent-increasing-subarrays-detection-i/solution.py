class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        for i in range(len(nums) - 2 * k + 1):
            sub1 = nums[i:i + k]
            sub2 = nums[i + k:i + 2 * k]
            is_increasing1 = all(sub1[j] < sub1[j + 1] for j in range(k - 1))
            is_increasing2 = all(sub2[j] < sub2[j + 1] for j in range(k - 1))
            if is_increasing1 and is_increasing2:
                return True
        return False