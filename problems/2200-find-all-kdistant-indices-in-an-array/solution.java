import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        List<Integer> result = new ArrayList<>();
        List<Integer> keyIndices = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == key) {
                keyIndices.add(i);
            }
        }
        for (int i = 0; i < nums.length; i++) {
            boolean isKDistant = false;
            for (int keyIndex : keyIndices) {
                if (Math.abs(i - keyIndex) <= k) {
                    isKDistant = true;
                    break;
                }
            }
            if (isKDistant) {
                result.add(i);
            }
        }
        return result;
    }
}