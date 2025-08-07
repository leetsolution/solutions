from collections import deque
from typing import List

class Solution:
    def generatePrimes(self, max_val: int) -> List[bool]:
        N = 5 * max_val + 1
        is_prime = [True] * N
        is_prime[0] = is_prime[1] = False

        for i in range(2, int(N ** 0.5) + 1):
            if is_prime[i]:
                for j in range(i * i, N, i):
                    is_prime[j] = False

        return is_prime

    def insertPrimeDQ(self, min_dq: deque, max_dq: deque, nums: List[int], idx: int):
        while min_dq and nums[min_dq[-1]] > nums[idx]:
            min_dq.pop()
        min_dq.append(idx)

        while max_dq and nums[max_dq[-1]] < nums[idx]:
            max_dq.pop()
        max_dq.append(idx)

    def primeSubarray(self, nums: List[int], k: int) -> int:
        max_num = max(nums)
        is_prime = self.generatePrimes(max_num)

        min_dq = deque()
        max_dq = deque()
        prime_dq = deque()

        left = 0
        prev_prime = 0
        result = 0

        for i, num in enumerate(nums):
            if is_prime[num]:
                self.insertPrimeDQ(min_dq, max_dq, nums, i)
                if prime_dq:
                    prev_prime = prime_dq[-1]
                prime_dq.append(i)

                while nums[max_dq[0]] - nums[min_dq[0]] > k:
                    remove_idx = prime_dq.popleft()
                    left = remove_idx + 1

                    if min_dq and min_dq[0] <= remove_idx:
                        min_dq.popleft()
                    if max_dq and max_dq[0] <= remove_idx:
                        max_dq.popleft()

            if len(prime_dq) >= 2:
                result += prev_prime - left + 1

        return result
