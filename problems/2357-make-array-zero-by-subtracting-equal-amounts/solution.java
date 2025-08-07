import java.util.HashSet;
import java.util.Set;

class Solution {
    public int minimumOperations(int[] nums) {
        Set<Integer> distinctPositiveNums = new HashSet<>();
        for (int num : nums) {
            if (num > 0) {
                distinctPositiveNums.add(num);
            }
        }
        return distinctPositiveNums.size();
    }
}