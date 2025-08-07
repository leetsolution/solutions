class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        try:
            index = word.index(ch)
            prefix = word[:index+1]
            reversed_prefix = prefix[::-1]
            return reversed_prefix + word[index+1:]
        except ValueError:
            return word