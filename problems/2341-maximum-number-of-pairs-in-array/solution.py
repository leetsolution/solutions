class Solution:
    def numberOfPairs(self, nums: List[int]) -> List[int]:
        counts = {}
        for num in nums:
            counts[num] = counts.get(num, 0) + 1
        
        pairs = 0
        leftover = 0
        
        for count in counts.values():
            pairs += count // 2
            leftover += count % 2
            
        return [pairs, leftover]