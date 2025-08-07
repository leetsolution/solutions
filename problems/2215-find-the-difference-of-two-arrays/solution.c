/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
    int* diff1 = (int*)malloc(sizeof(int) * 1001);
    int* diff2 = (int*)malloc(sizeof(int) * 1001);
    int diff1Size = 0;
    int diff2Size = 0;
    int hash1[2001] = {0};
    int hash2[2001] = {0};
    int* temp1 = (int*)malloc(sizeof(int) * nums1Size);
    int* temp2 = (int*)malloc(sizeof(int) * nums2Size);
    int temp1Size = 0;
    int temp2Size = 0;

    for (int i = 0; i < nums1Size; i++) {
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (nums1[i] == temp1[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            temp1[temp1Size++] = nums1[i];
        }
    }
    for (int i = 0; i < nums2Size; i++) {
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (nums2[i] == temp2[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            temp2[temp2Size++] = nums2[i];
        }
    }

    for (int i = 0; i < temp1Size; i++) {
        int found = 0;
        for (int j = 0; j < temp2Size; j++) {
            if (temp1[i] == temp2[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            diff1[diff1Size++] = temp1[i];
        }
    }

    for (int i = 0; i < temp2Size; i++) {
        int found = 0;
        for (int j = 0; j < temp1Size; j++) {
            if (temp2[i] == temp1[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            diff2[diff2Size++] = temp2[i];
        }
    }

    int** result = (int**)malloc(sizeof(int*) * 2);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2);

    result[0] = (int*)malloc(sizeof(int) * diff1Size);
    result[1] = (int*)malloc(sizeof(int) * diff2Size);

    for (int i = 0; i < diff1Size; i++) {
        result[0][i] = diff1[i];
    }

    for (int i = 0; i < diff2Size; i++) {
        result[1][i] = diff2[i];
    }

    (*returnColumnSizes)[0] = diff1Size;
    (*returnColumnSizes)[1] = diff2Size;
    *returnSize = 2;

    free(diff1);
    free(diff2);
    free(temp1);
    free(temp2);

    return result;
}