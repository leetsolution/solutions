class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int[] charMap = new int[26];
        for (int i = 0; i < order.length(); i++) {
            charMap[order.charAt(i) - 'a'] = i;
        }

        for (int i = 0; i < words.length - 1; i++) {
            String word1 = words[i];
            String word2 = words[i + 1];
            int minLength = Math.min(word1.length(), word2.length());

            boolean foundDiff = false;
            for (int j = 0; j < minLength; j++) {
                char char1 = word1.charAt(j);
                char char2 = word2.charAt(j);

                if (char1 != char2) {
                    if (charMap[char1 - 'a'] > charMap[char2 - 'a']) {
                        return false;
                    }
                    foundDiff = true;
                    break;
                }
            }

            if (!foundDiff && word1.length() > word2.length()) {
                return false;
            }
        }

        return true;
    }
}