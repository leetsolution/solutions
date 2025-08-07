class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        if not arr:
            return arr

        max_right = -1
        for i in range(len(arr) - 1, -1, -1):
            temp = arr[i]
            arr[i] = max_right
            max_right = max(max_right, temp)

        return arr