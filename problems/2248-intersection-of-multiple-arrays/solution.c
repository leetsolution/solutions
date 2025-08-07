/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    int i, j, k;
    int min_len = numsColSize[0];
    for (i = 1; i < numsSize; i++) {
        if (numsColSize[i] < min_len) {
            min_len = numsColSize[i];
        }
    }
    int *result = (int *)malloc(min_len * sizeof(int));
    int result_size = 0;
    for (i = 0; i < numsColSize[0]; i++) {
        int num = nums[0][i];
        int count = 1;
        for (j = 1; j < numsSize; j++) {
            int found = 0;
            for (k = 0; k < numsColSize[j]; k++) {
                if (nums[j][k] == num) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                count = 0;
                break;
            }
        }
        if (count) {
            int duplicate = 0;
            for(k=0; k<result_size; ++k){
                if(result[k] == num){
                    duplicate = 1;
                    break;
                }
            }
            if(!duplicate){
                result[result_size++] = num;
            }
        }
    }
    int *sorted_result = (int *)malloc(result_size * sizeof(int));
    for(i=0; i<result_size; ++i){
        sorted_result[i] = result[i];
    }
    qsort(sorted_result, result_size, sizeof(int), compare);
    free(result);
    *returnSize = result_size;
    return sorted_result;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}