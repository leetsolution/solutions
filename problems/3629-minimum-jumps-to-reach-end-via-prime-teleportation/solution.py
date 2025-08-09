from collections import deque
from typing import List

class Solution:
    def minJumps(self, nums: List[int]) -> int:
        n = len(nums)
        primes = self.find_primes(max(nums) + 1)
        prime_indices = {}
        for i in range(n):
            if nums[i] in primes:
                prime_indices[i] = nums[i]

        q = deque([(0, 0)])
        visited = {0}
        reachable = [False] * n
        reachable[0] = True

        while q:
            curr, dist = q.popleft()
            if curr == n - 1:
                return dist

            next_indices = []
            if curr + 1 < n:
                next_indices.append(curr + 1)
            if curr - 1 >= 0:
                next_indices.append(curr - 1)

            if curr in prime_indices:
                p = prime_indices[curr]
                for j in range(n):
                    if j != curr and nums[j] % p == 0:
                        next_indices.append(j)
                del prime_indices[curr]

            for neighbor in next_indices:
                if 0 <= neighbor < n and neighbor not in visited:
                    q.append((neighbor, dist + 1))
                    visited.add(neighbor)
                    reachable[neighbor] = True

        return -1

    def find_primes(self, limit):
        is_prime = [True] * limit
        is_prime[0] = is_prime[1] = False
        for i in range(2, int(limit**0.5) + 1):
            if is_prime[i]:
                for j in range(i*i, limit, i):
                    is_prime[j] = False
        
        primes = set()
        for i in range(2, limit):
            if is_prime[i]:
                primes.add(i)
        return primes