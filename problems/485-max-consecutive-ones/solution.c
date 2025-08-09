int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max_count = 0;
    int current_count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            current_count++;
        } else {
            max_count = (current_count > max_count) ? current_count : max_count;
            current_count = 0;
        }
    }
    max_count = (current_count > max_count) ? current_count : max_count;
    return max_count;
}