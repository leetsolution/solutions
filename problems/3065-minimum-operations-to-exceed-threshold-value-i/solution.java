import java.util.Arrays;

class Solution {
    public int minOperations(int[] nums, int k) {
        int operations = 0;
        Arrays.sort(nums);
        for (int num : nums) {
            if (num < k) {
                operations++;
            } else {
                break;
            }
        }
        return operations;
    }
}