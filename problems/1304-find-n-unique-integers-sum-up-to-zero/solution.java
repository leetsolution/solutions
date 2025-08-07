class Solution {
    public int[] sumZero(int n) {
        int[] result = new int[n];
        int start = -n / 2;
        if (n % 2 == 0) {
            start = -n / 2 + 1;
        }

        for (int i = 0; i < n; i++) {
            result[i] = start;
            start++;
        }

        return result;
    }
}