class Solution {
    public String longestNiceSubstring(String s) {
        if (s == null || s.length() < 2) {
            return "";
        }

        String longestNiceSubstring = "";

        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j <= s.length(); j++) {
                String sub = s.substring(i, j);
                if (isNice(sub)) {
                    if (sub.length() > longestNiceSubstring.length()) {
                        longestNiceSubstring = sub;
                    }
                }
            }
        }

        return longestNiceSubstring;
    }

    private boolean isNice(String s) {
        if (s == null || s.length() == 0) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isUpperCase(c)) {
                if (s.indexOf(Character.toLowerCase(c)) == -1) {
                    return false;
                }
            } else {
                if (s.indexOf(Character.toUpperCase(c)) == -1) {
                    return false;
                }
            }
        }

        return true;
    }
}