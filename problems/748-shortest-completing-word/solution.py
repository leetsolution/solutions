class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        count = {}
        for char in licensePlate.lower():
            if 'a' <= char <= 'z':
                count[char] = count.get(char, 0) + 1
        
        res = ""
        for word in words:
            valid = True
            temp_count = count.copy()
            for char in word:
                if char in temp_count:
                    temp_count[char] -= 1
                    if temp_count[char] == 0:
                        del temp_count[char]
            
            if not temp_count:
                if not res or len(word) < len(res):
                    res = word
        return res