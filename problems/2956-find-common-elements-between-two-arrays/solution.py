class Solution:
    def findIntersectionValues(self, nums1: List[int], nums2: List[int]) -> List[int]:
        answer1 = 0
        answer2 = 0
        set1 = set(nums1)
        set2 = set(nums2)
        for num in nums1:
            if num in set2:
                answer1 += 1
        for num in nums2:
            if num in set1:
                answer2 += 1
        return [answer1, answer2]