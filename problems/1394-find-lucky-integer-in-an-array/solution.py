from typing import List

class Solution:
    def findLucky(self, arr: List[int]) -> int:
        counts = {}
        for num in arr:
            counts[num] = counts.get(num, 0) + 1
        
        lucky_numbers = []
        for num, count in counts.items():
            if num == count:
                lucky_numbers.append(num)
        
        if not lucky_numbers:
            return -1
        else:
            return max(lucky_numbers)