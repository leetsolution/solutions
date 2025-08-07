class Solution:
    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        def get_num(word):
            s = ""
            for char in word:
                s += str(ord(char) - ord('a'))
            return int(s)
        
        return get_num(firstWord) + get_num(secondWord) == get_num(targetWord)