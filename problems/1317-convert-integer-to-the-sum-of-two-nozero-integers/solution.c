/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getNoZeroIntegers(int n, int* returnSize) {
    int *result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    for (int a = 1; a < n; a++) {
        int b = n - a;
        int temp_a = a;
        int temp_b = b;
        int has_zero_a = 0;
        int has_zero_b = 0;

        while (temp_a > 0) {
            if (temp_a % 10 == 0) {
                has_zero_a = 1;
                break;
            }
            temp_a /= 10;
        }

        while (temp_b > 0) {
            if (temp_b % 10 == 0) {
                has_zero_b = 1;
                break;
            }
            temp_b /= 10;
        }

        if (has_zero_a == 0 && has_zero_b == 0) {
            result[0] = a;
            result[1] = b;
            return result;
        }
    }
    return result;
}