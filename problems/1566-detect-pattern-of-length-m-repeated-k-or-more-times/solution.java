class Solution {
    public boolean containsPattern(int[] arr, int m, int k) {
        int n = arr.length;
        for (int i = 0; i <= n - m * k; i++) {
            boolean found = true;
            for (int j = 1; j < k; j++) {
                for (int l = 0; l < m; l++) {
                    if (arr[i + l] != arr[i + j * m + l]) {
                        found = false;
                        break;
                    }
                }
                if (!found) break;
            }
            if (found) return true;
        }
        return false;
    }
}