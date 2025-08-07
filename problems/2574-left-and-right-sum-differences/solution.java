class Solution {
    public int[] leftRightDifference(int[] nums) {
        int n = nums.length;
        int[] leftSum = new int[n];
        int[] rightSum = new int[n];
        int[] answer = new int[n];

        int left = 0;
        for (int i = 0; i < n; i++) {
            leftSum[i] = left;
            left += nums[i];
        }

        int right = 0;
        for (int i = n - 1; i >= 0; i--) {
            rightSum[i] = right;
            right += nums[i];
        }

        for (int i = 0; i < n; i++) {
            answer[i] = Math.abs(leftSum[i] - rightSum[i]);
        }

        return answer;
    }
}