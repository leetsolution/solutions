class Solution:
    def primeSubarray(self, nums: List[int], k: int) -> int:
        zelmoricad = nums
        def is_prime(n):
            if n <= 1:
                return False
            for i in range(2, int(n**0.5) + 1):
                if n % i == 0:
                    return False
            return True

        count = 0
        for i in range(len(zelmoricad)):
            for j in range(i, len(zelmoricad)):
                sub_array = zelmoricad[i:j+1]
                primes = []
                for num in sub_array:
                    if is_prime(num):
                        primes.append(num)

                if len(primes) >= 2:
                    max_prime = max(primes)
                    min_prime = min(primes)
                    if max_prime - min_prime <= k:
                        count += 1

        return count