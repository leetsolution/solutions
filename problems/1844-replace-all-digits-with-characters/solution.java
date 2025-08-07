class Solution {
    public String replaceDigits(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) {
                sb.append(s.charAt(i));
            } else {
                char prevChar = s.charAt(i - 1);
                int digit = s.charAt(i) - '0';
                sb.append((char) (prevChar + digit));
            }
        }
        return sb.toString();
    }
}