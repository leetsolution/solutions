class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        s1 = set(nums1)
        s2 = set(nums2)
        s3 = set(nums3)
        result = set()
        for num in s1:
            if num in s2 or num in s3:
                result.add(num)
        for num in s2:
            if num in s1 or num in s3:
                result.add(num)
        for num in s3:
            if num in s1 or num in s2:
                result.add(num)
        return list(result)