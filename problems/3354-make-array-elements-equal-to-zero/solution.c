int countValidSelections(int* nums, int numsSize) {
    int count = 0;
    for (int start = 0; start < numsSize; start++) {
        if (nums[start] == 0) {
            for (int dir = 0; dir < 2; dir++) {
                int curr = start;
                int direction = dir == 0 ? 1 : -1;
                int temp_nums[100];
                for (int i = 0; i < numsSize; i++) {
                    temp_nums[i] = nums[i];
                }
                int all_zeros = 1;
                while (curr >= 0 && curr < numsSize) {
                    if (temp_nums[curr] == 0) {
                        curr += direction;
                    } else {
                        temp_nums[curr]--;
                        direction *= -1;
                        curr += direction;
                    }
                }
                for (int i = 0; i < numsSize; i++) {
                    if (temp_nums[i] != 0) {
                        all_zeros = 0;
                        break;
                    }
                }
                if (all_zeros) {
                    count++;
                }
            }
        }
    }
    return count;
}