import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution {
    public boolean equalFrequency(String word) {
        int[] freq = new int[26];
        for (char c : word.toCharArray()) {
            freq[c - 'a']++;
        }

        for (int i = 0; i < word.length(); i++) {
            int[] tempFreq = new int[26];
            System.arraycopy(freq, 0, tempFreq, 0, 26);
            tempFreq[word.charAt(i) - 'a']--;

            Set<Integer> frequencies = new HashSet<>();
            boolean possible = true;
            for (int j = 0; j < 26; j++) {
                if (tempFreq[j] > 0) {
                    frequencies.add(tempFreq[j]);
                }
            }

            if (frequencies.size() > 1) {
                possible = false;
            }

            if (possible) {
                return true;
            }
        }

        return false;
    }
}