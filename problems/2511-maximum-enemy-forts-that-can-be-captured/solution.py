from typing import List

class Solution:
    def captureForts(self, forts: List[int]) -> int:
        n = len(forts)
        max_captured = 0
        last_fort = -1

        for i in range(n):
            if forts[i] == 1 or forts[i] == -1:
                if last_fort != -1 and forts[i] != forts[last_fort]:
                    captured = 0
                    for j in range(min(i, last_fort) + 1, max(i, last_fort)):
                        if forts[j] == 0:
                            captured += 1
                    max_captured = max(max_captured, captured)
                last_fort = i

        return max_captured