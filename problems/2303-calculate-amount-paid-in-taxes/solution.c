double calculateTax(int** brackets, int bracketsSize, int* bracketsColSize, int income) {
    double tax = 0.0;
    int prev = 0;
    for (int i = 0; i < bracketsSize; i++) {
        int upper = brackets[i][0];
        int percent = brackets[i][1];
        int taxable = upper - prev;
        if (income >= taxable) {
            tax += (double)taxable * percent / 100.0;
            income -= taxable;
        } else {
            tax += (double)income * percent / 100.0;
            income = 0;
            break;
        }
        prev = upper;
    }
    return tax;
}