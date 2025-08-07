import java.util.List;

class Solution {
    public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
        for (int a = 0; a <= nums.size() - 2 * k; a++) {
            int b = a + k;
            boolean increasingA = true;
            for (int i = a; i < a + k - 1; i++) {
                if (nums.get(i) >= nums.get(i + 1)) {
                    increasingA = false;
                    break;
                }
            }
            boolean increasingB = true;
            for (int i = b; i < b + k - 1; i++) {
                if (nums.get(i) >= nums.get(i + 1)) {
                    increasingB = false;
                    break;
                }
            }
            if (increasingA && increasingB) {
                return true;
            }
        }
        return false;
    }
}