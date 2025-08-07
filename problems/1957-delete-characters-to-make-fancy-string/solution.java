class Solution {
    public String makeFancyString(String s) {
        StringBuilder sb = new StringBuilder();
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (sb.length() > 0 && sb.charAt(sb.length() - 1) == s.charAt(i)) {
                count++;
                if (count < 2) {
                    sb.append(s.charAt(i));
                }
            } else {
                sb.append(s.charAt(i));
                count = 0;
            }
        }
        return sb.toString();
    }
}