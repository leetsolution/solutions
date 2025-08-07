class Solution {
    public int maximumValue(String[] strs) {
        int maxValue = 0;
        for (String str : strs) {
            boolean isNumeric = true;
            for (int i = 0; i < str.length(); i++) {
                if (!Character.isDigit(str.charAt(i))) {
                    isNumeric = false;
                    break;
                }
            }
            int value;
            if (isNumeric) {
                value = Integer.parseInt(str);
            } else {
                value = str.length();
            }
            maxValue = Math.max(maxValue, value);
        }
        return maxValue;
    }
}