class Solution:
    def checkRecord(self, s: str) -> bool:
        absent_count = s.count('A')
        late_count = 0
        max_late_count = 0
        for char in s:
            if char == 'L':
                late_count += 1
            else:
                max_late_count = max(max_late_count, late_count)
                late_count = 0
        max_late_count = max(max_late_count, late_count)
        return absent_count < 2 and max_late_count < 3