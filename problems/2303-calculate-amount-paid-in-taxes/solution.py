class Solution:
    def calculateTax(self, brackets: List[List[int]], income: int) -> float:
        tax = 0.0
        prev_upper = 0
        for upper, percent in brackets:
            if income <= 0:
                break
            taxable = min(income, upper - prev_upper)
            tax += taxable * percent / 100.0
            income -= taxable
            prev_upper = upper
        return tax