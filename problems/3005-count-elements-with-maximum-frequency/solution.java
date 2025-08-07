class Solution {
    public int maxFrequencyElements(int[] nums) {
        int[] counts = new int[101];
        int maxFreq = 0;
        for (int num : nums) {
            counts[num]++;
            maxFreq = Math.max(maxFreq, counts[num]);
        }
        int result = 0;
        for (int i = 1; i <= 100; i++) {
            if (counts[i] == maxFreq) {
                result += counts[i];
            }
        }
        return result;
    }
}