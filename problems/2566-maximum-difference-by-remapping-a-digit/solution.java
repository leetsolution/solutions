class Solution {
    public int minMaxDifference(int num) {
        String s = String.valueOf(num);
        int n = s.length();

        char maxDigit = ' ';
        for (int i = 0; i < n; i++) {
            if (maxDigit == ' ') {
                maxDigit = s.charAt(i);
                break;
            }
        }

        String maxNumStr = s.replace(maxDigit, '9');
        int maxNum = Integer.parseInt(maxNumStr);

        char minDigit = ' ';
        for (int i = 0; i < n; i++) {
            if (minDigit == ' ') {
                minDigit = s.charAt(i);
                break;
            }
        }

        String minNumStr = s.replace(minDigit, '0');
        int minNum = Integer.parseInt(minNumStr);
        

        return maxNum - minNum;
    }
}