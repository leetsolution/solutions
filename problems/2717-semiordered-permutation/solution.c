int semiOrderedPermutation(int* nums, int numsSize) {
    int oneIndex = -1;
    int nIndex = -1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            oneIndex = i;
        }
        if (nums[i] == numsSize) {
            nIndex = i;
        }
    }
    int result = oneIndex + (numsSize - 1 - nIndex);
    if (oneIndex > nIndex) {
        result--;
    }
    return result;
}