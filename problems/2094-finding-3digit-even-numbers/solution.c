/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findEvenNumbers(int* digits, int digitsSize, int* returnSize) {
    int count[10] = {0};
    for (int i = 0; i < digitsSize; i++) {
        count[digits[i]]++;
    }

    int* result = (int*)malloc(sizeof(int) * 1000);
    *returnSize = 0;

    for (int i = 100; i <= 999; i += 2) {
        int d1 = i / 100;
        int d2 = (i % 100) / 10;
        int d3 = i % 10;

        int tempCount[10] = {0};
        tempCount[d1]++;
        tempCount[d2]++;
        tempCount[d3]++;

        if (count[d1] >= tempCount[d1] &&
            count[d2] >= tempCount[d2] &&
            count[d3] >= tempCount[d3]) {
            result[(*returnSize)++] = i;
        }
    }

    int* finalResult = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        finalResult[i] = result[i];
    }

    free(result);
    return finalResult;
}