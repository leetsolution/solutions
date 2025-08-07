class Solution:
    def minimumChairs(self, s: str) -> int:
        chairs = 0
        max_chairs = 0
        for char in s:
            if char == 'E':
                chairs += 1
                max_chairs = max(max_chairs, chairs)
            else:
                chairs -= 1
        return max_chairs