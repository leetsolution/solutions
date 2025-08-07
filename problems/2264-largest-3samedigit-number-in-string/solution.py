class Solution:
    def largestGoodInteger(self, num: str) -> str:
        max_good = ""
        for i in range(len(num) - 2):
            if num[i] == num[i+1] and num[i+1] == num[i+2]:
                current_good = num[i:i+3]
                if max_good == "" or current_good > max_good:
                    max_good = current_good
        return max_good