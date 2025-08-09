class Solution {
    public String processStr(String s) {
        StringBuilder result = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (Character.isLetter(c)) {
                result.append(c);
            } else if (c == '*') {
                if (result.length() > 0) {
                    result.deleteCharAt(result.length() - 1);
                }
            } else if (c == '#') {
                String temp = result.toString();
                result.append(temp);
            } else if (c == '%') {
                result.reverse();
            }
        }
        return result.toString();
    }
}