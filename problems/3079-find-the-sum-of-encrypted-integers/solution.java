class Solution {
    public int sumOfEncryptedInt(int[] nums) {
        int sum = 0;
        for (int num : nums) {
            sum += encrypt(num);
        }
        return sum;
    }

    private int encrypt(int num) {
        String s = String.valueOf(num);
        int maxDigit = 0;
        for (char c : s.toCharArray()) {
            maxDigit = Math.max(maxDigit, c - '0');
        }
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            result = result * 10 + maxDigit;
        }
        return result;
    }
}