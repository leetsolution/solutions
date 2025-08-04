import java.util.*;
class Solution {
    public List<String> partitionString(String s) {
        List<String> result = new ArrayList<>();
        HashSet<Character> seen = new HashSet<>();
        StringBuilder current = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (seen.contains(c)) {
                result.add(current.toString());
                current.setLength(0);
                seen.clear();
            }
            current.append(c);
            seen.add(c);
        }
        if (current.length() > 0) {
            result.add(current.toString());
        }
        return result;
    }
}