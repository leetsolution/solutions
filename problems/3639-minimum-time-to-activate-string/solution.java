import java.util.TreeSet;

class Solution {
    public int minTime(String s, int[] order, int k) {
        int n = s.length();
        long total = (long) n * (n + 1) / 2;
        if (k > total) return -1;
        // TreeSet to keep track of removed positions (with sentinels)
        TreeSet<Integer> removed = new TreeSet<>();
        removed.add(-1);
        removed.add(n);
        long substringsWithoutStar = total;
        for (int t = 0; t < n; t++) {
            int idx = order[t];
            // Find the left and right boundaries of the current segment
            int left = removed.lower(idx);
            int right = removed.higher(idx);
            // Remove the old segment's contribution
            long len = right - left - 1;
            substringsWithoutStar -= len * (len + 1) / 2;
            // Add the two new segments' contributions
            long leftLen = idx - left - 1;
            long rightLen = right - idx - 1;
            substringsWithoutStar += leftLen * (leftLen + 1) / 2;
            substringsWithoutStar += rightLen * (rightLen + 1) / 2;
            removed.add(idx);
            long substringsWithStar = total - substringsWithoutStar;
            if (substringsWithStar >= k) return t;
        }
        return -1;
    }
}