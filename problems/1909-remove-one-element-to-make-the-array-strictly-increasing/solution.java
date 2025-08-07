class Solution {
    public boolean canBeIncreasing(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            int[] temp = new int[nums.length - 1];
            int k = 0;
            for (int j = 0; j < nums.length; j++) {
                if (j != i) {
                    temp[k++] = nums[j];
                }
            }
            boolean increasing = true;
            for (int j = 1; j < temp.length; j++) {
                if (temp[j] <= temp[j - 1]) {
                    increasing = false;
                    break;
                }
            }
            if (increasing) {
                return true;
            }
        }
        return false;
    }
}