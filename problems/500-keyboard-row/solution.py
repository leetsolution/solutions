class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        row1 = "qwertyuiop"
        row2 = "asdfghjkl"
        row3 = "zxcvbnm"
        result = []
        for word in words:
            word = word.lower()
            row = ""
            flag = True
            for char in word:
                if char in row1:
                    if row == "" or row == "row1":
                        row = "row1"
                    elif row != "row1":
                        flag = False
                        break
                elif char in row2:
                    if row == "" or row == "row2":
                        row = "row2"
                    elif row != "row2":
                        flag = False
                        break
                elif char in row3:
                    if row == "" or row == "row3":
                        row = "row3"
                    elif row != "row3":
                        flag = False
                        break
            if flag:
                result.append(word)
        return result