/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
    int i = numSize - 1;
    int carry = 0;
    int* result = (int*)malloc(10005 * sizeof(int));
    int resultIndex = 0;

    while (i >= 0 || k > 0 || carry > 0) {
        int digit1 = (i >= 0) ? num[i] : 0;
        int digit2 = k % 10;
        k /= 10;

        int sum = digit1 + digit2 + carry;
        result[resultIndex++] = sum % 10;
        carry = sum / 10;

        i--;
    }

    int* finalResult = (int*)malloc(resultIndex * sizeof(int));
    *returnSize = resultIndex;

    for (int j = 0; j < resultIndex; j++) {
        finalResult[j] = result[resultIndex - 1 - j];
    }

    free(result);
    return finalResult;
}