class Solution {
    public String removeDigit(String number, char digit) {
        String maxNum = "";
        for (int i = 0; i < number.length(); i++) {
            if (number.charAt(i) == digit) {
                String currentNum = number.substring(0, i) + number.substring(i + 1);
                if (maxNum.equals("") || Long.parseLong(currentNum) > Long.parseLong(maxNum)) {
                    maxNum = currentNum;
                }
            }
        }
        return maxNum;
    }
}