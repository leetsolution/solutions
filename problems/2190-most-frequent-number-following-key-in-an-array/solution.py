class Solution:
    def mostFrequent(self, nums: List[int], key: int) -> int:
        count = {}
        for i in range(len(nums) - 1):
            if nums[i] == key:
                if nums[i+1] not in count:
                    count[nums[i+1]] = 0
                count[nums[i+1]] += 1
        max_count = 0
        max_target = -1
        for target, c in count.items():
            if c > max_count:
                max_count = c
                max_target = target
        return max_target