class Solution {
    public String maximumOddBinaryNumber(String s) {
        int ones = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') {
                ones++;
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < ones - 1; i++) {
            sb.append('1');
        }

        int zeros = s.length() - ones;
        for (int i = 0; i < zeros; i++) {
            sb.append('0');
        }

        sb.append('1');

        return sb.toString();
    }
}