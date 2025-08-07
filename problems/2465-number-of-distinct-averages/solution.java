import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int distinctAverages(int[] nums) {
        Arrays.sort(nums);
        Set<Double> averages = new HashSet<>();
        int left = 0;
        int right = nums.length - 1;
        while (left < right) {
            double average = (double) (nums[left] + nums[right]) / 2;
            averages.add(average);
            left++;
            right--;
        }
        return averages.size();
    }
}