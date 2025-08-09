class Solution {
    public String resultingString(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (sb.length() > 0) {
                char last = sb.charAt(sb.length() - 1);
                if ((Math.abs(c - last) == 1) || (c == 'a' && last == 'z') || (c == 'z' && last == 'a')) {
                    sb.deleteCharAt(sb.length() - 1);
                } else {
                    sb.append(c);
                }
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}