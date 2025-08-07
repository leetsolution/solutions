class Solution {
    public void duplicateZeros(int[] arr) {
        int zeros = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 0) {
                zeros++;
            }
        }

        int n = arr.length;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] == 0) {
                if (i + zeros < n) {
                    arr[i + zeros] = 0;
                }
                zeros--;
                if (i + zeros < n) {
                    arr[i + zeros] = 0;
                }
            } else {
                if (i + zeros < n) {
                    arr[i + zeros] = arr[i];
                }
            }
        }
    }
}