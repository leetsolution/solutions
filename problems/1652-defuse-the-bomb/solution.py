class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        decrypted_code = [0] * n
        
        if k == 0:
            return decrypted_code
        
        for i in range(n):
            sum_val = 0
            if k > 0:
                for j in range(1, k + 1):
                    sum_val += code[(i + j) % n]
            else:
                for j in range(1, abs(k) + 1):
                    sum_val += code[(i - j) % n]
            decrypted_code[i] = sum_val
        
        return decrypted_code