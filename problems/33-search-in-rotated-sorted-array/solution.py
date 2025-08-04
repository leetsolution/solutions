class Solution:
    def search(self, arr, target):
        n = len(arr)
        pivot = self.findPivot(arr)
        if pivot == -1:
            return self.binarysearch(arr, 0, n - 1, target)
        if arr[pivot] == target:
            return pivot
        if target >= arr[0]:
            return self.binarysearch(arr, 0, pivot - 1, target)
        return self.binarysearch(arr, pivot + 1, n - 1, target)

    def findPivot(self, arr):
        l, r = 0, len(arr) - 1
        while l < r:
            mid = l + (r - l) // 2
            if arr[mid] > arr[r]:
                l = mid + 1
            else:
                r = mid
        return -1 if l == 0 else l - 1

    def binarysearch(self, arr, left, right, x):
        while left <= right:
            mid = left + (right - left) // 2
            if arr[mid] == x:
                return mid
            elif arr[mid] < x:
                left = mid + 1
            else:
                right = mid - 1
        return -1
