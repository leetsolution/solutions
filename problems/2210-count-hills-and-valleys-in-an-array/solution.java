class Solution {
    public int countHillValley(int[] nums) {
        int count = 0;
        for (int i = 1; i < nums.length - 1; i++) {
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 && nums[left] == nums[i]) {
                left--;
            }
            while (right < nums.length && nums[right] == nums[i]) {
                right++;
            }
            if (left >= 0 && right < nums.length) {
                if ((nums[i] > nums[left] && nums[i] > nums[right]) || (nums[i] < nums[left] && nums[i] < nums[right])) {
                    count++;
                }
            }
        }
        return count;
    }
}