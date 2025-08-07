class Solution:
    def getSmallestString(self, s: str) -> str:
        s_list = list(s)
        for i in range(len(s_list)):
            best_idx = i
            for j in range(i + 1, len(s_list)):
                if (int(s_list[i]) % 2 == int(s_list[j]) % 2) and (s_list[j] < s_list[best_idx]):
                    best_idx = j
            if best_idx != i:
                s_list[i], s_list[best_idx] = s_list[best_idx], s_list[i]
        return "".join(s_list)