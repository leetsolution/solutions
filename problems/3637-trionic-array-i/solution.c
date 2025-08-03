bool isTrionic(int* nums, int numsSize) {
    bool isTrionic(int* nums, int numsSize){
        for (int p = 1; p < numsSize - 1; p++) {
            for (int q = p + 1; q < numsSize - 1; q++) {
                bool inc1 = true, dec2 = true, inc3 = true;

                // Check nums[0...p] is strictly increasing
                for (int i = 1; i <= p; i++) {
                    if (nums[i] <= nums[i - 1]) {
                        inc1 = false;
                        break;
                    }
                }

                // Check nums[p...q] is strictly decreasing
                for (int i = p + 1; i <= q; i++) {
                    if (nums[i] >= nums[i - 1]) {
                        dec2 = false;
                        break;
                    }
                }

                // Check nums[q...numsSize-1] is strictly increasing
                for (int i = q + 1; i < numsSize; i++) {
                    if (nums[i] <= nums[i - 1]) {
                        inc3 = false;
                        break;
                    }
                }

                if (inc1 && dec2 && inc3) return true;
            }
        }
        return false;
    }
}