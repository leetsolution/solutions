class Solution {
    public int smallestIndex(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            int digitSum = 0;
            String numStr = String.valueOf(num);
            for (int j = 0; j < numStr.length(); j++) {
                digitSum += Character.getNumericValue(numStr.charAt(j));
            }
            if (digitSum == i) {
                return i;
            }
        }
        return -1;
    }
}