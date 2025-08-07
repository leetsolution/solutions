class Solution {
    public int findTheLongestBalancedSubstring(String s) {
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j <= s.length(); j++) {
                String sub = s.substring(i, j);
                int zeros = 0;
                int ones = 0;
                boolean balanced = true;
                boolean oneStarted = false;

                for (int k = 0; k < sub.length(); k++) {
                    if (sub.charAt(k) == '0') {
                        if (oneStarted) {
                            balanced = false;
                            break;
                        }
                        zeros++;
                    } else {
                        ones++;
                        oneStarted = true;
                    }
                }
                if (balanced && zeros == ones) {
                    maxLen = Math.max(maxLen, sub.length());
                }
            }
        }
        return maxLen;
    }
}