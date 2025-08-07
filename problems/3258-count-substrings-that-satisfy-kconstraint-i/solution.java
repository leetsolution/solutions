class Solution {
    public int countKConstraintSubstrings(String s, int k) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                String sub = s.substring(i, j + 1);
                int zeros = 0;
                int ones = 0;
                for (char c : sub.toCharArray()) {
                    if (c == '0') {
                        zeros++;
                    } else {
                        ones++;
                    }
                }
                if (zeros <= k || ones <= k) {
                    count++;
                }
            }
        }
        return count;
    }
}