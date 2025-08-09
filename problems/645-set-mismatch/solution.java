class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int[] count = new int[n + 1];
        int duplicate = 0;
        int missing = 0;
        long sum = 0;
        long expectedSum = (long) n * (n + 1) / 2;

        for (int num : nums) {
            count[num]++;
            sum += num;
        }

        for (int i = 1; i <= n; i++) {
            if (count[i] == 2) {
                duplicate = i;
            }
            if (count[i] == 0) {
                missing = i;
            }
        }
        
        return new int[]{duplicate, missing};
    }
}