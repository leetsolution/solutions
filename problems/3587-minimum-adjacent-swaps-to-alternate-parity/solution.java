class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length;
        int evenStart = 0, oddStart = 0;
        int evenCount = 0, oddCount = 0;
        for (int num : nums) {
            if (num % 2 == 0) evenCount++;
            else oddCount++;
        }
        if (Math.abs(evenCount - oddCount) > 1) return -1;
        // Try starting with even
        int swapsEven = 0, swapsOdd = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (nums[i] % 2 != 0) swapsEven++;
            } else {
                if (nums[i] % 2 == 0) swapsEven++;
            }
        }
        // Try starting with odd
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (nums[i] % 2 == 0) swapsOdd++;
            } else {
                if (nums[i] % 2 != 0) swapsOdd++;
            }
        }
        int res = Integer.MAX_VALUE;
        if (evenCount >= oddCount) res = Math.min(res, swapsEven / 2);
        if (oddCount >= evenCount) res = Math.min(res, swapsOdd / 2);
        return res == Integer.MAX_VALUE ? -1 : res;
    }
}