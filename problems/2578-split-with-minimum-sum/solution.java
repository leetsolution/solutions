class Solution {
    public int splitNum(int num) {
        String s = String.valueOf(num);
        char[] digits = s.toCharArray();
        Arrays.sort(digits);
        String num1 = "";
        String num2 = "";
        for (int i = 0; i < digits.length; i++) {
            if (i % 2 == 0) {
                num1 += digits[i];
            } else {
                num2 += digits[i];
            }
        }
        return Integer.parseInt(num1) + Integer.parseInt(num2);
    }
}