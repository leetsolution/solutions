class Solution:
    def countValidSelections(self, nums: List[int]) -> int:
        n = len(nums)
        count = 0
        for start_index in range(n):
            if nums[start_index] == 0:
                for direction in [1, -1]:
                    temp_nums = nums[:]
                    curr = start_index
                    curr_direction = direction
                    valid = True
                    while 0 <= curr < n:
                        if temp_nums[curr] == 0:
                            curr += curr_direction
                        else:
                            temp_nums[curr] -= 1
                            curr_direction *= -1
                            curr += curr_direction

                    if all(x == 0 for x in temp_nums):
                        count += 1

        return count