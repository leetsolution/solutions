/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;
    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;
        if (carry == 0) {
            *returnSize = digitsSize;
            return digits;
        }
    }
    if (carry > 0) {
        int* newDigits = (int*)malloc(sizeof(int) * (digitsSize + 1));
        newDigits[0] = carry;
        for (int i = 0; i < digitsSize; i++) {
            newDigits[i + 1] = digits[i];
        }
        *returnSize = digitsSize + 1;
        return newDigits;
    }
    *returnSize = digitsSize;
    return digits;
}