class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        operations = 0
        while True:
            min_sum = float('inf')
            min_index = -1

            for i in range(len(nums) - 1):
                current_sum = nums[i] + nums[i + 1]
                if current_sum < min_sum:
                    min_sum = current_sum
                    min_index = i

            if min_index == -1:
                is_sorted = True
                for i in range(len(nums) - 1):
                    if nums[i] > nums[i + 1]:
                        is_sorted = False
                        break
                if is_sorted:
                    return operations
                else:
                    return operations + len(nums) -1
            

            nums[min_index] = nums[min_index] + nums[min_index + 1]
            nums.pop(min_index + 1)
            operations += 1