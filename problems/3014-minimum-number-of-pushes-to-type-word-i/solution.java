import java.util.Arrays;

class Solution {
    public int minimumPushes(String word) {
        int[] freq = new int[26];
        for (char c : word.toCharArray()) {
            freq[c - 'a']++;
        }
        Arrays.sort(freq);
        int pushes = 0;
        int count = 1;
        int keys = 8;
        for (int i = 25; i >= 0; i--) {
            if (freq[i] == 0) break;
            pushes += freq[i] * count;
            keys--;
            if (keys == 0) {
                count++;
                keys = 8;
            }
        }
        return pushes;
    }
}