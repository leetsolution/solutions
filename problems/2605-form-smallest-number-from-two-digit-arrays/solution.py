class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        s1 = set(nums1)
        s2 = set(nums2)
        intersection = s1.intersection(s2)
        if intersection:
            return min(intersection)
        else:
            min1 = min(nums1)
            min2 = min(nums2)
            return min1 * 10 + min2 if min1 < min2 else min2 * 10 + min1