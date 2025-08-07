class Solution:
    def diagonalPrime(self, nums: List[List[int]]) -> int:
        def is_prime(n):
            if n <= 1:
                return False
            for i in range(2, int(n**0.5) + 1):
                if n % i == 0:
                    return False
            return True

        n = len(nums)
        primes = []
        for i in range(n):
            val1 = nums[i][i]
            if is_prime(val1):
                primes.append(val1)
            val2 = nums[i][n - 1 - i]
            if is_prime(val2) and val1 != val2:
                primes.append(val2)

        if not primes:
            return 0
        else:
            return max(primes)