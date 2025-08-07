import java.util.HashMap;
import java.util.Map;

class Solution {
    public int duplicateNumbersXOR(int[] nums) {
        Map<Integer, Integer> counts = new HashMap<>();
        int xorSum = 0;

        for (int num : nums) {
            counts.put(num, counts.getOrDefault(num, 0) + 1);
        }

        for (Map.Entry<Integer, Integer> entry : counts.entrySet()) {
            if (entry.getValue() == 2) {
                xorSum ^= entry.getKey();
            }
        }

        return xorSum;
    }
}