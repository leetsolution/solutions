int findGCD(int* nums, int numsSize) {
    int minVal = nums[0];
    int maxVal = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < minVal) {
            minVal = nums[i];
        }
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }
    
    int a = maxVal;
    int b = minVal;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}