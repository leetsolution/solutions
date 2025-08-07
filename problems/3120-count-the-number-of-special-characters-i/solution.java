class Solution {
    public int numberOfSpecialChars(String word) {
        int count = 0;
        boolean[] lowercase = new boolean[26];
        boolean[] uppercase = new boolean[26];

        for (char c : word.toCharArray()) {
            if (Character.isLowerCase(c)) {
                lowercase[c - 'a'] = true;
            } else {
                uppercase[c - 'A'] = true;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (lowercase[i] && uppercase[i]) {
                count++;
            }
        }

        return count;
    }
}