class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        nums = set()
        current_num = ""
        for char in word:
            if char.isdigit():
                current_num += char
            else:
                if current_num:
                    nums.add(int(current_num))
                    current_num = ""
        if current_num:
            nums.add(int(current_num))
        return len(nums)