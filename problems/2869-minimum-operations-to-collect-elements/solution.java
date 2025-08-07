import java.util.List;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int minOperations(List<Integer> nums, int k) {
        Set<Integer> collected = new HashSet<>();
        int operations = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            operations++;
            int num = nums.get(i);
            if (num >= 1 && num <= k) {
                collected.add(num);
            }
            if (collected.size() == k) {
                return operations;
            }
        }
        return operations;
    }
}