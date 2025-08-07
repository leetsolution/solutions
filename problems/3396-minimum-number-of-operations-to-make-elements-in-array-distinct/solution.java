import java.util.HashSet;
import java.util.Set;

class Solution {
    public int minimumOperations(int[] nums) {
        int n = nums.length;
        if (n == 0) {
            return 0;
        }
        int operations = 0;
        for (int i = 0; i <= n / 3; i++) {
            int remainingLength = n - i * 3;
            if (remainingLength <= 0) {
                return i;
            }
            int[] remainingNums = new int[remainingLength];
            for (int j = 0; j < remainingLength; j++) {
                remainingNums[j] = nums[i * 3 + j];
            }
            Set<Integer> distinctElements = new HashSet<>();
            boolean distinct = true;
            for (int num : remainingNums) {
                if (distinctElements.contains(num)) {
                    distinct = false;
                    break;
                }
                distinctElements.add(num);
            }
            if (distinct) {
                return i;
            }
        }
        return n / 3 + 1;
    }
}