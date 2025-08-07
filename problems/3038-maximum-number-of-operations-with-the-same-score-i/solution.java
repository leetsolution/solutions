class Solution {
    public int maxOperations(int[] nums) {
        int operations = 0;
        if (nums.length < 2) {
            return 0;
        }
        int targetSum = nums[0] + nums[1];
        operations++;
        for (int i = 2; i < nums.length - 1; i += 2) {
            if (nums[i] + nums[i + 1] == targetSum) {
                operations++;
            } else {
                break;
            }
        }
        return operations;
    }
}