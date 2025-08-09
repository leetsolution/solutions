class Solution:
    def minTime(self, s: str, order: List[int], k: int) -> int:
        n = len(s)

        def count_valid_substrings(temp_s):
            count = 0
            for i in range(n):
                for j in range(i, n):
                    substring = temp_s[i:j+1]
                    if '*' in substring:
                        count += 1
            return count

        for t in range(n):
            temp_s = list(s)
            for i in range(t + 1):
                temp_s[order[i]] = '*'
            temp_s = "".join(temp_s)
            
            if count_valid_substrings(temp_s) >= k:
                return t
        
        return -1