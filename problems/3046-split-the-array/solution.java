import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean isPossibleToSplit(int[] nums) {
        Map<Integer, Integer> counts = new HashMap<>();
        for (int num : nums) {
            counts.put(num, counts.getOrDefault(num, 0) + 1);
        }

        for (int count : counts.values()) {
            if (count > nums.length / 2) {
                return false;
            }
        }

        return true;
    }
}