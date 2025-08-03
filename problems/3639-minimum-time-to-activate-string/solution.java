class Solution {
    public int minTime(String s, int[] order, int k) {
    class Solution {
        public int minTimeToActivateString(String s, int[] order, long k) {
            int n = s.length();
            char[] chars = s.toCharArray();
            long maxValidSubstrings = (long) n * (n + 1) / 2;

            if (k > maxValidSubstrings) return -1;

            for (int t = 0; t < n; t++) {
                chars[order[t]] = '*';
                long validSubstrings = countValidSubstrings(chars);
                if (validSubstrings >= k) return t;
            }
            return -1;
        }

        private long countValidSubstrings(char[] chars) {
            long count = 0;
            for (int i = 0; i < chars.length; i++) {
                if (chars[i] == '*') {
                    for (int j = i; j < chars.length; j++) {
                        count++;
                    }
                    break;
                }
            }

            long validCount = 0;
            for (int i = 0; i < chars.length; i++) {
                for (int j = i; j < chars.length; j++) {
                    boolean hasStar = false;
                    for (int l = i; l <= j; l++) {
                        if (chars[l] == '*') {
                            hasStar = true;
                            break;
                        }
                    }
                    if (hasStar) validCount++;
                }
            }
            return validCount;
        }
    }
}