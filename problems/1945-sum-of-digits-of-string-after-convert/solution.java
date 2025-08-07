class Solution {
    public int getLucky(String s, int k) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            sb.append(c - 'a' + 1);
        }
        String converted = sb.toString();
        int num = 0;
        for (int i = 0; i < converted.length(); i++) {
            num += converted.charAt(i) - '0';
        }
        for (int i = 1; i < k; i++) {
            int sum = 0;
            String numStr = String.valueOf(num);
            for (int j = 0; j < numStr.length(); j++) {
                sum += numStr.charAt(j) - '0';
            }
            num = sum;
        }
        return num;
    }
}