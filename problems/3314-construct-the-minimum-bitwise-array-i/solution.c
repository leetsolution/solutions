/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    int *ans = (int *)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int x = num - 1;
        if ((x | (x + 1)) == num) {
            ans[i] = x;
        } else {
            x = num - 1;
            int y = x & (x +1);
            if(y == 0){
                ans[i] = -1;
            } else {
                int k = 0;
                while (((k | (k + 1)) & num) != num) {
                    k++;
                }
                ans[i] = k;

            }
           
        }
    }
    return ans;
}