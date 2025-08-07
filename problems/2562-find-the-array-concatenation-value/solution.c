long long findTheArrayConcVal(int* nums, int numsSize) {
    long long concatenationValue = 0;
    int left = 0;
    int right = numsSize - 1;
    while (left <= right) {
        long long num1 = nums[left];
        long long num2 = nums[right];
        long long concatenatedNum;
        if (left == right) {
            concatenatedNum = num1;
        } else {
            long long powerOf10 = 1;
            long long temp = num2;
            while (temp > 0) {
                powerOf10 *= 10;
                temp /= 10;
            }
            concatenatedNum = num1 * powerOf10 + num2;
        }
        concatenationValue += concatenatedNum;
        left++;
        right--;
    }
    return concatenationValue;
}