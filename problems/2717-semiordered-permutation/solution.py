class Solution:
    def semiOrderedPermutation(self, nums: List[int]) -> int:
        n = len(nums)
        pos1 = nums.index(1)
        posN = nums.index(n)
        
        ans = pos1 + (n - 1 - posN)
        
        if pos1 > posN:
            ans -= 1
            
        return ans