/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *result = (int *)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    int i,j,k=0;
    int *count1 = (int *)calloc(1001, sizeof(int));
    int *count2 = (int *)calloc(1001, sizeof(int));

    for(i=0; i<nums1Size; i++){
        count1[nums1[i]]++;
    }
    for(i=0; i<nums2Size; i++){
        count2[nums2[i]]++;
    }

    for(i=0; i<=1000; i++){
        int count = count1[i] < count2[i] ? count1[i] : count2[i];
        for(j=0; j<count; j++){
            result[k++] = i;
        }
    }
    *returnSize = k;
    free(count1);
    free(count2);
    return result;
}