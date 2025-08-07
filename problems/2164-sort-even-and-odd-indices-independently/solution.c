/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortEvenOdd(int* nums, int numsSize, int* returnSize) {
    int evenCount = 0;
    int oddCount = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    int* even = (int*)malloc(evenCount * sizeof(int));
    int* odd = (int*)malloc(oddCount * sizeof(int));

    int evenIndex = 0;
    int oddIndex = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            even[evenIndex++] = nums[i];
        } else {
            odd[oddIndex++] = nums[i];
        }
    }

    for (int i = 0; i < evenCount - 1; i++) {
        for (int j = 0; j < evenCount - i - 1; j++) {
            if (even[j] > even[j + 1]) {
                int temp = even[j];
                even[j] = even[j + 1];
                even[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < oddCount - 1; i++) {
        for (int j = 0; j < oddCount - i - 1; j++) {
            if (odd[j] < odd[j + 1]) {
                int temp = odd[j];
                odd[j] = odd[j + 1];
                odd[j + 1] = temp;
            }
        }
    }

    evenIndex = 0;
    oddIndex = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            nums[i] = even[evenIndex++];
        } else {
            nums[i] = odd[oddIndex++];
        }
    }

    free(even);
    free(odd);

    *returnSize = numsSize;
    return nums;
}