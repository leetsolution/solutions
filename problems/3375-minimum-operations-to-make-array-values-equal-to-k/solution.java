class Solution {
    public int minOperations(int[] nums, int k) {
        int operations = 0;
        while (true) {
            boolean allEqual = true;
            for (int num : nums) {
                if (num != k) {
                    allEqual = false;
                    break;
                }
            }
            if (allEqual) {
                return operations;
            }

            int maxVal = -1;
            for (int num : nums) {
                maxVal = Math.max(maxVal, num);
            }

            if (k > maxVal) {
                return -1;
            }
            
            int validH = -1;
            for(int h = maxVal - 1; h >= k; h--){
                boolean isValid = true;
                int greaterVal = -1;
                boolean foundGreater = false;
                for(int num : nums){
                    if(num > h){
                        if(!foundGreater){
                            greaterVal = num;
                            foundGreater = true;
                        } else if(num != greaterVal){
                            isValid = false;
                            break;
                        }
                    }
                }
                if(isValid){
                    validH = h;
                    break;
                }
            }

            if (validH == -1) {
                if(k == maxVal){
                    return -1;
                }
                
                
                int count = 0;
                for(int i = 0; i < nums.length; i++){
                    if(nums[i] > k){
                        nums[i] = k;
                        count++;
                    }
                }
                 if (count > 0) {
                    return operations + count;
                 }else{
                    return -1;
                 }
            } else {
                for (int i = 0; i < nums.length; i++) {
                    if (nums[i] > validH) {
                        nums[i] = validH;
                    }
                }
                operations++;
            }
        }
    }
}