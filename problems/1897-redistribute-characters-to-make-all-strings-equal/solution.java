class Solution {
    public boolean makeEqual(String[] words) {
        int[] charCounts = new int[26];
        for (String word : words) {
            for (char c : word.toCharArray()) {
                charCounts[c - 'a']++;
            }
        }

        int numWords = words.length;
        for (int count : charCounts) {
            if (count % numWords != 0) {
                return false;
            }
        }

        return true;
    }
}