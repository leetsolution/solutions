class Solution {
    public int mostFrequentEven(int[] nums) {
        int[] count = new int[100001];
        int maxFreq = 0;
        int mostFrequent = -1;

        for (int num : nums) {
            if (num % 2 == 0) {
                count[num]++;
                if (count[num] > maxFreq) {
                    maxFreq = count[num];
                    mostFrequent = num;
                } else if (count[num] == maxFreq && num < mostFrequent) {
                    mostFrequent = num;
                }
            }
        }

        return mostFrequent;
    }
}