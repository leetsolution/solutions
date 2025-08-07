import java.util.List;
import java.util.HashSet;

class Solution {
    public int numberOfPoints(List<List<Integer>> nums) {
        HashSet<Integer> points = new HashSet<>();
        for (List<Integer> interval : nums) {
            int start = interval.get(0);
            int end = interval.get(1);
            for (int i = start; i <= end; i++) {
                points.add(i);
            }
        }
        return points.size();
    }
}