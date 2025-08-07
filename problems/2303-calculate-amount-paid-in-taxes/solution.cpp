class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0.0;
        int prev_upper = 0;
        for (int i = 0; i < brackets.size(); ++i) {
            int upper = brackets[i][0];
            int percent = brackets[i][1];
            int taxable = min(income, upper) - prev_upper;
            if (taxable > 0) {
                tax += (double)taxable * (double)percent / 100.0;
            }
            prev_upper = upper;
            if (income <= upper) {
                break;
            }
        }
        return tax;
    }
};