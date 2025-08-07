import java.util.HashSet;
import java.util.Set;

class Solution {
    public int[] distinctDifferenceArray(int[] nums) {
        int n = nums.length;
        int[] diff = new int[n];

        for (int i = 0; i < n; i++) {
            Set<Integer> prefixDistinct = new HashSet<>();
            for (int j = 0; j <= i; j++) {
                prefixDistinct.add(nums[j]);
            }

            Set<Integer> suffixDistinct = new HashSet<>();
            for (int j = i + 1; j < n; j++) {
                suffixDistinct.add(nums[j]);
            }

            diff[i] = prefixDistinct.size() - suffixDistinct.size();
        }

        return diff;
    }
}