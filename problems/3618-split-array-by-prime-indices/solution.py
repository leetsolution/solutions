class Solution:
    def splitArray(self, nums: List[int]) -> int:
        def is_prime(n):
            if n <= 1:
                return False
            for i in range(2, int(n**0.5) + 1):
                if n % i == 0:
                    return False
            return True

        A = []
        B = []
        for i in range(len(nums)):
            if is_prime(i):
                A.append(nums[i])
            else:
                B.append(nums[i])

        sum_A = sum(A)
        sum_B = sum(B)

        return abs(sum_A - sum_B)