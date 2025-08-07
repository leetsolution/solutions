class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> counts(101, 0);
        int max_freq = 0;
        for (int num : nums) {
            counts[num]++;
            max_freq = max(max_freq, counts[num]);
        }
        int result = 0;
        for (int count : nums) {
            if (counts[count] == max_freq) {
                result++;
            }
        }
        return result;
    }
};