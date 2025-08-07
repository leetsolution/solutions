class Solution:
    def kthCharacter(self, k: int) -> str:
        word = "a"
        count = 1
        while count < k:
            new_word = ""
            for char in word:
                new_word += chr(ord(char) + 1)
            word += new_word
            count = len(word)
        return word[k - 1]