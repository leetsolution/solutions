import java.util.List;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public List<String> partitionString(String s) {
        List<String> segments = new ArrayList<>();
        Set<String> seen = new HashSet<>();
        int n = s.length();
        int start = 0;
        while (start < n) {
            StringBuilder currentSegment = new StringBuilder();
            int current = start;
            while (current < n) {
                currentSegment.append(s.charAt(current));
                String segment = currentSegment.toString();
                if (!seen.contains(segment)) {
                    segments.add(segment);
                    seen.add(segment);
                    start = current + 1;
                    break;
                } else {
                    current++;
                }
            }
            if (current == n && start != current) {
                start = current;
            } else if (current == n && start == current) {
                break;
            }
        }
        return segments;
    }
}