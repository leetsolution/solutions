import java.util.HashSet;
import java.util.Set;

class Solution {
    public int findMaxK(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        int maxK = -1;

        for (int num : nums) {
            seen.add(num);
        }

        for (int num : nums) {
            if (num > 0 && seen.contains(-num)) {
                maxK = Math.max(maxK, num);
            }
        }

        return maxK;
    }
}