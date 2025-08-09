class Solution {
    public int countBinarySubstrings(String s) {
        int[] groups = new int[s.length()];
        int i = 0, j = 0;
        while (i < s.length()) {
            char c = s.charAt(i);
            int count = 0;
            while (i < s.length() && s.charAt(i) == c) {
                i++;
                count++;
            }
            groups[j++] = count;
        }
        int ans = 0;
        for (int k = 1; k < j; k++) {
            ans += Math.min(groups[k - 1], groups[k]);
        }
        return ans;
    }
}