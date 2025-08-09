/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = nums1Size;
    int *ans = (int*)malloc(nums1Size * sizeof(int));
    for (int i = 0; i < nums1Size; i++) {
        int found = 0;
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                int nextGreater = -1;
                for (int k = j + 1; k < nums2Size; k++) {
                    if (nums2[k] > nums1[i]) {
                        nextGreater = nums2[k];
                        break;
                    }
                }
                ans[i] = nextGreater;
                found = 1;
                break;
            }
        }
    }
    return ans;
}