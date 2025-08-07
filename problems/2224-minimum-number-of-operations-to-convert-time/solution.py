class Solution:
    def convertTime(self, current: str, correct: str) -> int:
        current_h, current_m = map(int, current.split(':'))
        correct_h, correct_m = map(int, correct.split(':'))

        current_minutes = current_h * 60 + current_m
        correct_minutes = correct_h * 60 + correct_m

        diff = correct_minutes - current_minutes
        
        operations = 0
        operations += diff // 60
        diff %= 60
        operations += diff // 15
        diff %= 15
        operations += diff // 5
        diff %= 5
        operations += diff

        return operations