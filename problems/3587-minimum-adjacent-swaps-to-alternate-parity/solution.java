import java.util.ArrayList;
import java.util.List;

class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length;
        List<Integer> evenIndices = new ArrayList<>();
        List<Integer> oddIndices = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                evenIndices.add(i);
            } else {
                oddIndices.add(i);
            }
        }

        int evenCount = evenIndices.size();
        int oddCount = oddIndices.size();

        if (Math.abs(evenCount - oddCount) > 1) {
            return -1;
        }

        // Case 1: Target starts with Even (E, O, E, O...)
        long swaps1 = Long.MAX_VALUE;
        if (evenCount >= oddCount) { // This pattern is possible
            swaps1 = 0;
            // Calculate moves for odd numbers to get to odd positions
            for (int i = 0; i < oddCount; i++) {
                int targetIndex = 2 * i + 1;
                swaps1 += Math.abs(oddIndices.get(i) - targetIndex);
            }
        }

        // Case 2: Target starts with Odd (O, E, O, E...)
        long swaps2 = Long.MAX_VALUE;
        if (oddCount >= evenCount) { // This pattern is possible
            swaps2 = 0;
            // Calculate moves for even numbers to get to odd positions
            for (int i = 0; i < evenCount; i++) {
                int targetIndex = 2 * i + 1;
                swaps2 += Math.abs(evenIndices.get(i) - targetIndex);
            }
        }

        long result = Math.min(swaps1, swaps2);
        return result == Long.MAX_VALUE ? -1 : (int) result;
    }
}
