/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize) {
    int size = 0;
    for (int i = 0; i < numsSize; i += 2) {
        size += nums[i];
    }
    
    int* result = (int*)malloc(size * sizeof(int));
    *returnSize = size;
    
    int index = 0;
    for (int i = 0; i < numsSize; i += 2) {
        int freq = nums[i];
        int val = nums[i + 1];
        
        for (int j = 0; j < freq; j++) {
            result[index++] = val;
        }
    }
    
    return result;
}