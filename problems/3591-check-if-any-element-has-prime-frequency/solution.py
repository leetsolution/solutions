class Solution:
    def checkPrimeFrequency(self, nums: List[int]) -> bool:
        def is_prime(n):
            if n <= 1:
                return False
            for i in range(2, int(n**0.5) + 1):
                if n % i == 0:
                    return False
            return True

        counts = {}
        for num in nums:
            counts[num] = counts.get(num, 0) + 1

        for count in counts.values():
            if is_prime(count):
                return True

        return False