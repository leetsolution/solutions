class Solution {
    public boolean isSubstringPresent(String s) {
        if (s.length() < 2) {
            return false;
        }

        String reversedS = new StringBuilder(s).reverse().toString();

        for (int i = 0; i < s.length() - 1; i++) {
            String sub = s.substring(i, i + 2);
            if (reversedS.contains(sub)) {
                return true;
            }
        }

        return false;
    }
}