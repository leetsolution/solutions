class Solution {
    public int semiOrderedPermutation(int[] nums) {
        int n = nums.length;
        int indexOfOne = -1;
        int indexOfN = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                indexOfOne = i;
            }
            if (nums[i] == n) {
                indexOfN = i;
            }
        }

        int swaps = indexOfOne + (n - 1 - indexOfN);
        if (indexOfOne > indexOfN) {
            swaps--;
        }

        return swaps;
    }
}