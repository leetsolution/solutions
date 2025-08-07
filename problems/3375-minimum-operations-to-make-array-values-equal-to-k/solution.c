int minOperations(int* nums, int numsSize, int k) {
    int operations = 0;
    while (1) {
        int all_equal = 1;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] != k) {
                all_equal = 0;
                break;
            }
        }
        if (all_equal) {
            return operations;
        }

        int max_val = -1;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] > max_val) {
                max_val = nums[i];
            }
        }

        if (k > max_val) {
            return -1;
        }

        int valid_h = -1;
        for (int h = max_val - 1; h >= k; h--) {
            int count = 0;
            int val = -1;
            int is_valid = 1;
            for (int i = 0; i < numsSize; i++) {
                if (nums[i] > h) {
                    count++;
                    if (val == -1) {
                        val = nums[i];
                    } else if (val != nums[i]) {
                        is_valid = 0;
                        break;
                    }
                }
            }
            if (is_valid) {
                valid_h = h;
                break;
            }
        }

        if (valid_h == -1 && max_val > k) {
            
             int count = 0;
            int val = -1;
            int is_valid = 1;
            for (int i = 0; i < numsSize; i++) {
                if (nums[i] > max_val -1) {
                    count++;
                    if (val == -1) {
                        val = nums[i];
                    } else if (val != nums[i]) {
                        is_valid = 0;
                        break;
                    }
                }
            }
            
             if (is_valid){
                valid_h = max_val -1;
            }else{
                return -1;
            }
        }

        if(valid_h == -1 && max_val == k){
            return -1;
        }
        
        if (valid_h == -1 && max_val > k){
            return -1;
        }
        
        if (valid_h == -1) {
             
            return -1;
        }
        

        for (int i = 0; i < numsSize; i++) {
            if (nums[i] > valid_h) {
                nums[i] = valid_h;
            }
        }
        operations++;
    }
}