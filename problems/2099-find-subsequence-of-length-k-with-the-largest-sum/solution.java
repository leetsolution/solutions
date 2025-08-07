import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        int n = nums.length;
        int[] copy = Arrays.copyOf(nums, n);
        Arrays.sort(copy);

        Map<Integer, Integer> count = new HashMap<>();
        for (int i = n - k; i < n; i++) {
            count.put(copy[i], count.getOrDefault(copy[i], 0) + 1);
        }

        int[] result = new int[k];
        int index = 0;
        for (int num : nums) {
            if (count.containsKey(num) && count.get(num) > 0) {
                result[index++] = num;
                count.put(num, count.get(num) - 1);
                if (index == k) {
                    break;
                }
            }
        }

        return result;
    }
}