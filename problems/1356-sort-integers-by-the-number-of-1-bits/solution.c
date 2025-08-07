/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortByBits(int* arr, int arrSize, int* returnSize) {
    int* result = (int*)malloc(arrSize * sizeof(int));
    *returnSize = arrSize;

    int bitCounts[arrSize];
    for (int i = 0; i < arrSize; i++) {
        int num = arr[i];
        int count = 0;
        while (num > 0) {
            num &= (num - 1);
            count++;
        }
        bitCounts[i] = count;
    }

    for (int i = 0; i < arrSize; i++) {
        result[i] = arr[i];
    }

    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = 0; j < arrSize - i - 1; j++) {
            if (bitCounts[j] > bitCounts[j + 1] || (bitCounts[j] == bitCounts[j + 1] && result[j] > result[j + 1])) {
                int temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;

                int tempBit = bitCounts[j];
                bitCounts[j] = bitCounts[j + 1];
                bitCounts[j + 1] = tempBit;
            }
        }
    }

    return result;
}