class Solution {
    public int maximumLengthSubstring(String s) {
        int n = s.length();
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                String sub = s.substring(i, j + 1);
                boolean valid = true;
                for (char c = 'a'; c <= 'z'; c++) {
                    int count = 0;
                    for (int k = 0; k < sub.length(); k++) {
                        if (sub.charAt(k) == c) {
                            count++;
                        }
                    }
                    if (count > 2) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    maxLength = Math.max(maxLength, sub.length());
                }
            }
        }
        return maxLength;
    }
}