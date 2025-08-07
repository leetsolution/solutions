import java.util.*;
class Solution {
    public List<Integer> intersection(int[][] nums) {
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int[] num : nums) {
            for (int n : num) {
                countMap.put(n, countMap.getOrDefault(n, 0) + 1);
            }
        }
        List<Integer> result = new ArrayList<>();
        int len = nums.length;
        for (Map.Entry<Integer, Integer> entry : countMap.entrySet()) {
            if (entry.getValue() == len) {
                result.add(entry.getKey());
            }
        }
        Collections.sort(result);
        return result;
    }
}