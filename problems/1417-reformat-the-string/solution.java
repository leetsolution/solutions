class Solution {
    public String reformat(String s) {
        StringBuilder digits = new StringBuilder();
        StringBuilder letters = new StringBuilder();

        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                digits.append(c);
            } else {
                letters.append(c);
            }
        }

        if (Math.abs(digits.length() - letters.length()) > 1) {
            return "";
        }

        StringBuilder result = new StringBuilder();
        StringBuilder longer = (digits.length() > letters.length()) ? digits : letters;
        StringBuilder shorter = (digits.length() > letters.length()) ? letters : digits;

        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) {
                if (longer.length() > 0) {
                    result.append(longer.charAt(0));
                    longer.deleteCharAt(0);
                }
            } else {
                if (shorter.length() > 0) {
                    result.append(shorter.charAt(0));
                    shorter.deleteCharAt(0);
                }
            }
        }

        return result.toString();
    }
}