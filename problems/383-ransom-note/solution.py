class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mag_count = {}
        for char in magazine:
            mag_count[char] = mag_count.get(char, 0) + 1
        
        for char in ransomNote:
            if char not in mag_count or mag_count[char] == 0:
                return False
            mag_count[char] -= 1
        return True