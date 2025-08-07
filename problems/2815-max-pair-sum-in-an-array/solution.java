class Solution {
    public int maxSum(int[] nums) {
        int maxSum = -1;
        int[] maxDigitMap = new int[10];
        for (int num : nums) {
            int maxDigit = 0;
            int temp = num;
            while (temp > 0) {
                maxDigit = Math.max(maxDigit, temp % 10);
                temp /= 10;
            }
            if (maxDigitMap[maxDigit] != 0) {
                maxSum = Math.max(maxSum, maxDigitMap[maxDigit] + num);
            }
            maxDigitMap[maxDigit] = Math.max(maxDigitMap[maxDigit], num);
        }
        return maxSum;
    }
}