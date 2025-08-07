/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize) {
    int count[101] = {0};
    int* result = (int*)malloc(sizeof(int) * 101);
    *returnSize = 0;
    int seen1[101] = {0};
    int seen2[101] = {0};
    int seen3[101] = {0};

    for (int i = 0; i < nums1Size; i++) {
        if (seen1[nums1[i]] == 0) {
            count[nums1[i]]++;
            seen1[nums1[i]] = 1;
        }
    }
    for (int i = 0; i < nums2Size; i++) {
        if (seen2[nums2[i]] == 0) {
            count[nums2[i]]++;
            seen2[nums2[i]] = 1;
        }
    }
    for (int i = 0; i < nums3Size; i++) {
        if (seen3[nums3[i]] == 0) {
            count[nums3[i]]++;
            seen3[nums3[i]] = 1;
        }
    }

    for (int i = 1; i <= 100; i++) {
        if (count[i] >= 2) {
            result[(*returnSize)++] = i;
        }
    }

    return result;
}