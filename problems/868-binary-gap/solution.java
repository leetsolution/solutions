class Solution {
    public int binaryGap(int n) {
        String binary = Integer.toBinaryString(n);
        int maxGap = 0;
        int lastOne = -1;
        for (int i = 0; i < binary.length(); i++) {
            if (binary.charAt(i) == '1') {
                if (lastOne != -1) {
                    maxGap = Math.max(maxGap, i - lastOne);
                }
                lastOne = i;
            }
        }
        return maxGap;
    }
}