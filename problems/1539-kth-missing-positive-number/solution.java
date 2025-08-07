class Solution {
    public int findKthPositive(int[] arr, int k) {
        int missing = 0;
        int expected = 1;
        int i = 0;
        while (missing < k) {
            if (i < arr.length && arr[i] == expected) {
                i++;
            } else {
                missing++;
            }
            if (missing < k) {
                expected++;
            }
        }
        return expected;
    }
}