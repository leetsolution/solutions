class Solution:
    def minimum_time(s, order, k):
        n = len(s)
        s_list = list(s)

        def count_valid_substrings(string):
            count = 0
            for i in range(len(string)):
                for j in range(i, len(string)):
                    substring = string[i:j+1]
                    if '*' in substring:
                        count += 1
            return count

        for t in range(n):
            s_list[order[t]] = '*'
            if count_valid_substrings("".join(s_list)) >= k:
                return t
        return -1