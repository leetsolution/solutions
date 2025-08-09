import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> readBinaryWatch(int turnedOn) {
        List<String> result = new ArrayList<>();
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (Integer.bitCount(h) + Integer.bitCount(m) == turnedOn) {
                    String hour = String.valueOf(h);
                    String minute = String.format("%02d", m);
                    result.add(hour + ":" + minute);
                }
            }
        }
        return result;
    }
}