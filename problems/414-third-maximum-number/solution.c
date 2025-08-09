int thirdMax(int* nums, int numsSize) {
    long long first = LLONG_MIN, second = LLONG_MIN, third = LLONG_MIN;
    for (int i = 0; i < numsSize; i++) {
        long long num = nums[i];
        if (num > first) {
            third = second;
            second = first;
            first = num;
        } else if (num > second && num != first) {
            third = second;
            second = num;
        } else if (num > third && num != second && num != first) {
            third = num;
        }
    }
    return third == LLONG_MIN ? (int)first : (int)third;
}