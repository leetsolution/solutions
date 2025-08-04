import java.util.*;
class Solution {
    public int[] subarrayMajority(int[] nums, int[][] queries) {
        int q = queries.length;
        int[] ans = new int[q];
        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int threshold = queries[i][2];
            Map<Integer, Integer> freq = new HashMap<>();
            for (int j = l; j <= r; j++) {
                freq.put(nums[j], freq.getOrDefault(nums[j], 0) + 1);
            }
            int maxFreq = -1;
            int majorityElement = -1;
            for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
                if (entry.getValue() >= threshold) {
                    if (entry.getValue() > maxFreq) {
                        maxFreq = entry.getValue();
                        majorityElement = entry.getKey();
                    } else if (entry.getValue() == maxFreq && entry.getKey() < majorityElement) {
                        majorityElement = entry.getKey();
                    }
                }
            }
            ans[i] = majorityElement;
        }
        return ans;
    }
}