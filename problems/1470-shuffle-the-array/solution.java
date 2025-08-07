class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] result = new int[2 * n];
        int xIndex = 0;
        int yIndex = n;
        int resultIndex = 0;

        for (int i = 0; i < n; i++) {
            result[resultIndex++] = nums[xIndex++];
            result[resultIndex++] = nums[yIndex++];
        }

        return result;
    }
}