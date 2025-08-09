import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public int maxSubstrings(String word) {
        int n = word.length();
        int[] first = new int[26];
        int[] last = new int[26];
        for (int i = 0; i < 26; i++) {
            first[i] = n;
            last[i] = -1;
        }
        for (int i = 0; i < n; i++) {
            int c = word.charAt(i) - 'a';
            first[c] = Math.min(first[c], i);
            last[c] = Math.max(last[c], i);
        }

        List<int[]> intervals = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            if (first[i] < n) {
                int left = first[i];
                int right = last[i];
                int j = left;
                while (j <= right) {
                    int c = word.charAt(j) - 'a';
                    left = Math.min(left, first[c]);
                    right = Math.max(right, last[c]);
                    j++;
                }
                if (right - left + 1 >= 4) {
                    intervals.add(new int[]{left, right});
                }
            }
        }

        Collections.sort(intervals, (a, b) -> a[1] - b[1]);

        int count = 0;
        int end = -1;
        for (int[] interval : intervals) {
            if (interval[0] > end) {
                count++;
                end = interval[1];
            }
        }

        return count;
    }
}