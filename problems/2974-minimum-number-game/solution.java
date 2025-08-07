import java.util.Arrays;

class Solution {
    public int[] numberGame(int[] nums) {
        Arrays.sort(nums);
        int[] arr = new int[nums.length];
        for (int i = 0; i < nums.length; i += 2) {
            // In each round, Alice removes nums[i] and Bob removes nums[i+1]
            // Bob appends his number first, then Alice appends hers.
            arr[i] = nums[i + 1];
            arr[i + 1] = nums[i];
        }
        return arr;
    }
}