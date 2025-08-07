class Solution {
    public int maxLength(int[] nums) {
        int maxLen = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i; j < nums.length; j++) {
                int[] subArray = new int[j - i + 1];
                for (int k = i; k <= j; k++) {
                    subArray[k - i] = nums[k];
                }
                if (isProductEquivalent(subArray)) {
                    maxLen = Math.max(maxLen, subArray.length);
                }
            }
        }
        return maxLen;
    }

    private boolean isProductEquivalent(int[] arr) {
        if (arr.length == 0) {
            return false;
        }
        long product = 1;
        for (int num : arr) {
            product *= num;
        }
        long gcd = arr[0];
        for (int i = 1; i < arr.length; i++) {
            gcd = gcd(gcd, arr[i]);
        }
        long lcm = arr[0];
        for (int i = 1; i < arr.length; i++) {
            lcm = lcm(lcm, arr[i]);
        }
        return product == lcm * gcd;
    }

    private long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    private long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }
}