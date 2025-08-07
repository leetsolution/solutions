/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findXSum(int* nums, int numsSize, int k, int x, int* returnSize) {
    int* answer = (int*)malloc((numsSize - k + 1) * sizeof(int));
    *returnSize = numsSize - k + 1;
    for (int i = 0; i <= numsSize - k; i++) {
        int* subarray = (int*)malloc(k * sizeof(int));
        for (int j = 0; j < k; j++) {
            subarray[j] = nums[i + j];
        }
        int freq[51] = {0};
        for (int j = 0; j < k; j++) {
            freq[subarray[j]]++;
        }
        int count = 0;
        int top_x[51];
        int top_x_count[51];
        for (int j = 50; j >= 1; j--) {
            if (freq[j] > 0) {
                top_x[count] = j;
                top_x_count[count] = freq[j];
                count++;
                if (count == x)
                    break;
            }
        }
        int sum = 0;
        for (int j = 0; j < count; j++) {
            for (int l = 0; l < top_x_count[j]; l++) {
                sum += top_x[j];
            }
        }
        answer[i] = sum;
        free(subarray);
    }
    return answer;
}