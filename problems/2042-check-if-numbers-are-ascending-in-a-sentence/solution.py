class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        nums = []
        for token in s.split():
            if token.isdigit():
                nums.append(int(token))
        
        for i in range(1, len(nums)):
            if nums[i] <= nums[i-1]:
                return False
        
        return True