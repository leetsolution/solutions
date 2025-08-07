import java.util.List;
import java.util.HashSet;

class Solution {
    public int sumCounts(List<Integer> nums) {
        int n = nums.size();
        int sumOfSquares = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                HashSet<Integer> distinctElements = new HashSet<>();
                for (int k = i; k <= j; k++) {
                    distinctElements.add(nums.get(k));
                }
                sumOfSquares += distinctElements.size() * distinctElements.size();
            }
        }
        return sumOfSquares;
    }
}