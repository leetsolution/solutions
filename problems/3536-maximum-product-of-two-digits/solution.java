class Solution {
    public int maxProduct(int n) {
        String s = String.valueOf(n);
        int maxProduct = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length(); j++) {
                int digit1 = Character.getNumericValue(s.charAt(i));
                int digit2 = Character.getNumericValue(s.charAt(j));
                maxProduct = Math.max(maxProduct, digit1 * digit2);
            }
        }
        return maxProduct;
    }
}