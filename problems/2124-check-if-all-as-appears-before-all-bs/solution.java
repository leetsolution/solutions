class Solution {
    public boolean checkString(String s) {
        boolean bFound = false;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'b') {
                bFound = true;
            }
            if (bFound && s.charAt(i) == 'a') {
                return false;
            }
        }
        return true;
    }
}