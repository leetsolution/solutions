class Solution {
    public int countValidWords(String sentence) {
        int count = 0;
        String[] tokens = sentence.split("\\s+");
        for (String token : tokens) {
            if (isValid(token)) {
                count++;
            }
        }
        return count;
    }

    private boolean isValid(String token) {
        if (token.isEmpty()) {
            return false;
        }

        int hyphenCount = 0;
        int punctuationCount = 0;

        for (int i = 0; i < token.length(); i++) {
            char c = token.charAt(i);

            if (Character.isDigit(c)) {
                return false;
            } else if (c == '-') {
                hyphenCount++;
                if (hyphenCount > 1) {
                    return false;
                }
                if (i == 0 || i == token.length() - 1) {
                    return false;
                }
                if (!Character.isLowerCase(token.charAt(i - 1)) || !Character.isLowerCase(token.charAt(i + 1))) {
                    return false;
                }
            } else if (c == '!' || c == '.' || c == ',') {
                punctuationCount++;
                if (punctuationCount > 1) {
                    return false;
                }
                if (i != token.length() - 1) {
                    return false;
                }
            } else if (!Character.isLowerCase(c)) {
                return false;
            }
        }

        return true;
    }
}