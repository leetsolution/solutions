import java.util.HashMap;

class Solution {
    public int[] numberOfPairs(int[] nums) {
        HashMap<Integer, Integer> counts = new HashMap<>();
        for (int num : nums) {
            counts.put(num, counts.getOrDefault(num, 0) + 1);
        }
        int pairs = 0;
        int leftovers = 0;
        for (int count : counts.values()) {
            pairs += count / 2;
            leftovers += count % 2;
        }
        return new int[]{pairs, leftovers};
    }
}