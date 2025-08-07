class Solution {
    public int countVowelSubstrings(String word) {
        int count = 0;
        for (int i = 0; i < word.length(); i++) {
            for (int j = i; j < word.length(); j++) {
                String sub = word.substring(i, j + 1);
                if (isVowelSubstring(sub)) {
                    count++;
                }
            }
        }
        return count;
    }

    private boolean isVowelSubstring(String s) {
        String vowels = "aeiou";
        boolean a = false, e = false, i = false, o = false, u = false;
        for (int k = 0; k < s.length(); k++) {
            char c = s.charAt(k);
            if (vowels.indexOf(c) == -1) {
                return false;
            }
            if (c == 'a') a = true;
            if (c == 'e') e = true;
            if (c == 'i') i = true;
            if (c == 'o') o = true;
            if (c == 'u') u = true;
        }
        return a && e && i && o && u;
    }
}