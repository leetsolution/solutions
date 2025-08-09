class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        result = []
        for i in range(left, right + 1):
            num_str = str(i)
            is_self_dividing = True
            for digit in num_str:
                digit = int(digit)
                if digit == 0 or i % digit != 0:
                    is_self_dividing = False
                    break
            if is_self_dividing:
                result.append(i)
        return result