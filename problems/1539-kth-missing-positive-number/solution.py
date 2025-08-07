class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        missing = 0
        expected = 1
        i = 0
        while missing < k:
            if i < len(arr) and arr[i] == expected:
                i += 1
            else:
                missing += 1
            if missing < k:
                expected += 1
        return expected