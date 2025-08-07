class Solution {
    public boolean hasSpecialSubstring(String s, int k) {
        for (int i = 0; i <= s.length() - k; i++) {
            char c = s.charAt(i);
            boolean same = true;
            for (int j = i + 1; j < i + k; j++) {
                if (s.charAt(j) != c) {
                    same = false;
                    break;
                }
            }
            if (same) {
                boolean beforeDifferent = true;
                if (i > 0 && s.charAt(i - 1) == c) {
                    beforeDifferent = false;
                }
                boolean afterDifferent = true;
                if (i + k < s.length() && s.charAt(i + k) == c) {
                    afterDifferent = false;
                }
                if (beforeDifferent && afterDifferent) {
                    return true;
                }
            }
        }
        return false;
    }
}