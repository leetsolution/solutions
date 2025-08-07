class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        if s1 == s2:
            return True
        
        diff_indices = []
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                diff_indices.append(i)
        
        if len(diff_indices) == 2:
            i, j = diff_indices
            s1_list = list(s1)
            s1_list[i], s1_list[j] = s1_list[j], s1_list[i]
            return "".join(s1_list) == s2
        
        return False