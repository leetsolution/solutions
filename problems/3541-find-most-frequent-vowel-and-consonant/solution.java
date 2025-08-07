class Solution {
    public int maxFreqSum(String s) {
        int maxVowelFreq = 0;
        int maxConsonantFreq = 0;
        int[] vowelCounts = new int[5];
        int[] consonantCounts = new int[26];

        for (char c : s.toCharArray()) {
            if (isVowel(c)) {
                int index = getVowelIndex(c);
                vowelCounts[index]++;
            } else {
                consonantCounts[c - 'a']++;
            }
        }

        for (int count : vowelCounts) {
            maxVowelFreq = Math.max(maxVowelFreq, count);
        }

        for (int i = 0; i < 26; i++) {
            if (!isVowel((char)('a' + i))) {
                maxConsonantFreq = Math.max(maxConsonantFreq, consonantCounts[i]);
            }
        }

        return maxVowelFreq + maxConsonantFreq;
    }

    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    private int getVowelIndex(char c) {
        if (c == 'a') return 0;
        if (c == 'e') return 1;
        if (c == 'i') return 2;
        if (c == 'o') return 3;
        return 4;
    }
}