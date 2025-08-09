class Solution:
    def sumOfLargestPrimes(self, s: str) -> int:
        def is_prime(n):
            if n < 2:
                return False
            for i in range(2, int(n**0.5) + 1):
                if n % i == 0:
                    return False
            return True

        primes = set()
        for i in range(len(s)):
            for j in range(i, len(s)):
                sub = s[i:j+1]
                num = int(sub)
                if is_prime(num):
                    primes.add(num)

        primes = sorted(list(primes), reverse=True)
        
        if len(primes) == 0:
            return 0
        elif len(primes) < 3:
            return sum(primes)
        else:
            return sum(primes[:3])