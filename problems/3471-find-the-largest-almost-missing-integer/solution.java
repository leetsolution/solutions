class Solution {
    public int largestInteger(int[] nums, int k) {
        int n = nums.length;
        int[] counts = new int[101];
        for (int i = 0; i <= 100; i++) {
            counts[i] = 0;
        }

        for (int i = 0; i <= n - k; i++) {
            for (int j = i; j < i + k; j++) {
                counts[nums[j]]++;
            }
        }

        int largest = -1;
        for (int i = 100; i >= 0; i--) {
            int count = 0;
             for (int l = 0; l <= 100; l++) {
                counts[l] = 0;
             }
            
            for (int start = 0; start <= n - k; start++) {
                boolean found = false;
                for (int m = start; m < start + k; m++) {
                    if (nums[m] == i) {
                        found = true;
                        break;
                    }
                }
                if(found) count++;
            }
            if (count == 1) {
                largest = i;
                break;
            }
        }

        return largest;
    }
}