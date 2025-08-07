class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] charCounts = new int[26];
        for (char c : chars.toCharArray()) {
            charCounts[c - 'a']++;
        }

        int totalLength = 0;
        for (String word : words) {
            int[] wordCounts = new int[26];
            boolean good = true;
            for (char c : word.toCharArray()) {
                int index = c - 'a';
                wordCounts[index]++;
                if (wordCounts[index] > charCounts[index]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                totalLength += word.length();
            }
        }

        return totalLength;
    }
}