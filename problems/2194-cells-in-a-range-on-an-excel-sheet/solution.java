import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> cellsInRange(String s) {
        List<String> result = new ArrayList<>();
        char col1 = s.charAt(0);
        char col2 = s.charAt(3);
        int row1 = Integer.parseInt(String.valueOf(s.charAt(1)));
        int row2 = Integer.parseInt(String.valueOf(s.charAt(4)));

        for (char col = col1; col <= col2; col++) {
            for (int row = row1; row <= row2; row++) {
                result.add(String.valueOf(col) + row);
            }
        }
        return result;
    }
}