int missingInteger(int* nums, int numsSize) {
    int sum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1] + 1) {
            sum += nums[i];
        } else {
            break;
        }
    }

    int seen[51] = {0};
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= 50) {
            seen[nums[i]] = 1;
        }
    }

    int x = sum;
    while (x <= 50 && seen[x] == 1) {
        x++;
    }
    
    return x;
}