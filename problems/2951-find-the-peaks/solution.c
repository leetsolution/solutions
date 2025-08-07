/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findPeaks(int* mountain, int mountainSize, int* returnSize) {
    int count = 0;
    for (int i = 1; i < mountainSize - 1; i++) {
        if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]) {
            count++;
        }
    }
    
    *returnSize = count;
    int* result = (int*)malloc(count * sizeof(int));
    
    if (count == 0) {
        return result;
    }
    
    int idx = 0;
    for (int i = 1; i < mountainSize - 1; i++) {
        if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]) {
            result[idx++] = i;
        }
    }
    
    return result;
}