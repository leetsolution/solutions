class Solution {
    public String getSmallestString(String s) {
        char[] chars = s.toCharArray();
        int n = chars.length;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((chars[i] - '0') % 2 == (chars[j] - '0') % 2 && chars[j] < chars[i]) {
                    char temp = chars[i];
                    chars[i] = chars[j];
                    chars[j] = temp;
                }
            }
        }

        return new String(chars);
    }
}