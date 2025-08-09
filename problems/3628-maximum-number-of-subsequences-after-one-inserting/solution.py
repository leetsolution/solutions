class Solution:
    def numOfSubsequences(self, s: str) -> int:
        def count_subsequences(text):
            l_count = 0
            lc_count = 0
            lct_count = 0
            for char in text:
                if char == 'L':
                    l_count += 1
                elif char == 'C':
                    lc_count += l_count
                elif char == 'T':
                    lct_count += lc_count
            return lct_count

        max_count = 0
        for i in range(len(s) + 1):
            temp_s = s[:i] + 'L' + s[i:]
            max_count = max(max_count, count_subsequences(temp_s))
            
            temp_s = s[:i] + 'C' + s[i:]
            max_count = max(max_count, count_subsequences(temp_s))
            
            temp_s = s[:i] + 'T' + s[i:]
            max_count = max(max_count, count_subsequences(temp_s))

        return max_count