import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        Arrays.sort(nums);
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        List<Integer> result = new ArrayList<>();
        int subsequenceSum = 0;
        for (int i = nums.length - 1; i >= 0; i--) {
            result.add(nums[i]);
            subsequenceSum += nums[i];
            if (subsequenceSum > totalSum - subsequenceSum) {
                return result;
            }
        }
        return result;
    }
}