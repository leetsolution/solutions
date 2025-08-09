class Solution {
    public boolean checkRecord(String s) {
        int absentCount = 0;
        int lateCount = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == 'A') {
                absentCount++;
            } else if (c == 'L') {
                lateCount++;
            } else {
                lateCount = 0;
            }
            if (absentCount >= 2 || lateCount >= 3) {
                return false;
            }
        }
        return true;
    }
}