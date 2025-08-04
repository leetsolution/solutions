class Solution {
    public int maxSubsequences(String s) {
        int n = s.length();
        int lCount = 0, lcCount = 0, lctCount = 0;
        for (char c : s.toCharArray()) {
            if (c == 'T') {
                lctCount += lcCount;
                lcCount += lCount;
            } else if (c == 'C') {
                lcCount += lCount;
            } else if (c == 'L') {
                lCount++;
            }
        }
        int maxCount = lctCount;
        for (int i = 0; i <= n; i++) {
            int curLCount = 0, curLcCount = 0, curLctCount = 0;
            String temp = s.substring(0, i) + "L" + s.substring(i);
            for (char c : temp.toCharArray()) {
                if (c == 'T') {
                    curLctCount += curLcCount;
                    curLcCount += curLCount;
                } else if (c == 'C') {
                    curLcCount += curLCount;
                } else if (c == 'L') {
                    curLCount++;
                }
            }
            maxCount = Math.max(maxCount, curLctCount);
        }
        return maxCount;
    }
}