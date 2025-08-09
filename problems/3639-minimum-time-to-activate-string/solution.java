class Solution {
    public int minTime(String s, int[] order, int k) {
        int n = s.length();
        if (n * (n + 1L) / 2 < k) {
            return -1;
        }

        int left = 0;
        int right = n - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(s, order, mid, k)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }

    private boolean isValid(String s, int[] order, int time, int k) {
        int n = s.length();
        char[] chars = s.toCharArray();
        for (int i = 0; i <= time; i++) {
            chars[order[i]] = '*';
        }

        long count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                boolean hasStar = false;
                for (int l = i; l <= j; l++) {
                    if (chars[l] == '*') {
                        hasStar = true;
                        break;
                    }
                }
                if (hasStar) {
                    count++;
                }
            }
        }

        return count >= k;
    }
}