class Solution:
    def is_prime(n):
        if n <= 1:
            return False
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                return False
        return True

    def solve(nums):
        A = []
        B = []
        for i in range(len(nums)):
            if is_prime(i + 1):
                A.append(nums[i])
            else:
                B.append(nums[i])
        return abs(sum(A) - sum(B))