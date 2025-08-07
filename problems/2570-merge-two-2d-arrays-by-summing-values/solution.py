class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        merged = {}
        for id, val in nums1:
            merged[id] = val
        for id, val in nums2:
            if id in merged:
                merged[id] += val
            else:
                merged[id] = val
        result = []
        for id in sorted(merged.keys()):
            result.append([id, merged[id]])
        return result