int findShortestSubArray(int* nums, int numsSize) {
    int count[50000] = {0};
    int first[50000];
    int last[50000];
    int degree = 0;
    for (int i = 0; i < numsSize; i++) {
        if (count[nums[i]] == 0) {
            first[nums[i]] = i;
        }
        count[nums[i]]++;
        last[nums[i]] = i;
        degree = max(degree, count[nums[i]]);
    }
    int minLength = numsSize;
    for (int i = 0; i < 50000; i++) {
        if (count[i] == degree) {
            minLength = min(minLength, last[i] - first[i] + 1);
        }
    }
    return minLength;
}
int max(int a, int b) {
    return a > b ? a : b;
}
int min(int a, int b) {
    return a < b ? a : b;
}