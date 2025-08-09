from typing import List

class Solution:
    def minXor(self, nums: List[int], k: int) -> int:
        def check(threshold):
            count = 1
            current_xor = 0
            for num in nums:
                current_xor ^= num
                if current_xor > threshold:
                    count += 1
                    current_xor = num
                else:
                    current_xor = current_xor
            return count <= k

        left, right = 0, 0
        for num in nums:
            right ^= num

        ans = right
        while left <= right:
            mid = (left + right) // 2
            if check(mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans