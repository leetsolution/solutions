class Solution {
    public boolean backspaceCompare(String s, String t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        int backspaceS = 0;
        int backspaceT = 0;

        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s.charAt(i) == '#') {
                    backspaceS++;
                    i--;
                } else if (backspaceS > 0) {
                    backspaceS--;
                    i--;
                } else {
                    break;
                }
            }
            while (j >= 0) {
                if (t.charAt(j) == '#') {
                    backspaceT++;
                    j--;
                } else if (backspaceT > 0) {
                    backspaceT--;
                    j--;
                } else {
                    break;
                }
            }

            if (i >= 0 && j >= 0 && s.charAt(i) == t.charAt(j)) {
                i--;
                j--;
            } else if (i >= 0 || j >= 0) {
                return false;
            }
        }
        return true;
    }
}