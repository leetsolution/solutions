class Solution:
    def max_lct_subsequences(s):
        def count_subsequences(string):
            count = 0
            for i in range(len(string)):
                if string[i] == 'L':
                    for j in range(i + 1, len(string)):
                        if string[j] == 'C':
                            for k in range(j + 1, len(string)):
                                if string[k] == 'T':
                                    count += 1
            return count

        max_count = count_subsequences(s)
        for char in "LCT":
            for i in range(len(s) + 1):
                new_s = list(s)
                new_s.insert(i, char)
                max_count = max(max_count, count_subsequences("".join(new_s)))
        return max_count