int numberOfPoints(int** nums, int numsSize, int* numsColSize) {
    int count = 0;
    int covered[101] = {0};
    for (int i = 0; i < numsSize; i++) {
        for (int j = nums[i][0]; j <= nums[i][1]; j++) {
            if (covered[j] == 0) {
                covered[j] = 1;
                count++;
            }
        }
    }
    return count;
}