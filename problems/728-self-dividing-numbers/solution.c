/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int count = 0;
    for (int i = left; i <= right; i++) {
        int temp = i;
        int flag = 1;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit == 0 || i % digit != 0) {
                flag = 0;
                break;
            }
            temp /= 10;
        }
        if (flag)
            count++;
    }
    int *result = (int *)malloc(count * sizeof(int));
    *returnSize = count;
    int index = 0;
    for (int i = left; i <= right; i++) {
        int temp = i;
        int flag = 1;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit == 0 || i % digit != 0) {
                flag = 0;
                break;
            }
            temp /= 10;
        }
        if (flag) {
            result[index] = i;
            index++;
        }
    }
    return result;
}