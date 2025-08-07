/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * k);
    *returnSize = k;
    int* indices = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        indices[i] = i;
    }
    
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] < nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                
                temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }

    int* selectedIndices = (int*)malloc(sizeof(int) * k);
    for(int i = 0; i < k; i++){
        selectedIndices[i] = indices[i];
    }

    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < k - i - 1; j++) {
            if (selectedIndices[j] > selectedIndices[j + 1]) {
                int temp = selectedIndices[j];
                selectedIndices[j] = selectedIndices[j + 1];
                selectedIndices[j + 1] = temp;
            }
        }
    }
    
    for (int i = 0; i < k; i++) {
        result[i] = nums[0];
        for(int j = 0; j < numsSize; j++){
          if(selectedIndices[i] == indices[j]){
            result[i] = nums[j];
            break;
          }
        }
    }
    
    free(indices);
    free(selectedIndices);
    
    return result;
}