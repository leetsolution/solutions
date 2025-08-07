class Solution {
    public boolean halvesAreAlike(String s) {
        int mid = s.length() / 2;
        String a = s.substring(0, mid);
        String b = s.substring(mid);
        int countA = 0;
        int countB = 0;
        for (int i = 0; i < mid; i++) {
            char charA = a.charAt(i);
            char charB = b.charAt(i);
            if (isVowel(charA)) {
                countA++;
            }
            if (isVowel(charB)) {
                countB++;
            }
        }
        return countA == countB;
    }

    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
}