class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        res = ""
        for i in range(len(number)):
            if number[i] == digit:
                temp = number[:i] + number[i+1:]
                if res == "" or int(temp) > int(res):
                    res = temp
        return res