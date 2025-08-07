class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        counts = {}
        for char in s:
            counts[char] = counts.get(char, 0) + 1
        
        first_count = None
        for count in counts.values():
            if first_count is None:
                first_count = count
            elif count != first_count:
                return False
        
        return True