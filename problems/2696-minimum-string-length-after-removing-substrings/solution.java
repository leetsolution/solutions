class Solution {
    public int minLength(String s) {
        while (s.contains("AB") || s.contains("CD")) {
            if (s.contains("AB")) {
                s = s.replaceFirst("AB", "");
            } else {
                s = s.replaceFirst("CD", "");
            }
        }
        return s.length();
    }
}