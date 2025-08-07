class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        count = {}
        for num in nums:
            count[num] = count.get(num, 0) + 1
        result = []
        for num, freq in count.items():
            if freq == 2:
                result.append(num)
        return result