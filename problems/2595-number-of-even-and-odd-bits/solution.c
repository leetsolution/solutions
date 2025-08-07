/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* evenOddBit(int n, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    int even = 0;
    int odd = 0;
    int index = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            if (index % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        n /= 2;
        index++;
    }
    result[0] = even;
    result[1] = odd;
    return result;
}