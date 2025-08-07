class Solution:
    def sortEvenOdd(self, nums: List[int]) -> List[int]:
        odd_indices = []
        even_indices = []
        for i in range(len(nums)):
            if i % 2 == 0:
                even_indices.append(nums[i])
            else:
                odd_indices.append(nums[i])
        even_indices.sort()
        odd_indices.sort(reverse=True)
        result = []
        even_index = 0
        odd_index = 0
        for i in range(len(nums)):
            if i % 2 == 0:
                result.append(even_indices[even_index])
                even_index += 1
            else:
                result.append(odd_indices[odd_index])
                odd_index += 1
        return result