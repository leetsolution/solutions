class Solution {
    public int countLargestGroup(int n) {
        int[] count = new int[37];
        int maxCount = 0;
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            int num = i;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            count[sum]++;
            maxCount = Math.max(maxCount, count[sum]);
        }
        int result = 0;
        for (int i = 1; i < 37; i++) {
            if (count[i] == maxCount) {
                result++;
            }
        }
        return result;
    }
}