class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int result = 0;
        vector<int> counts(51, 0);

        for (int num : nums) {
            counts[num]++;
        }

        for (int i = 1; i <= 50; ++i) {
            if (counts[i] == 2) {
                result ^= i;
            }
        }

        return result;
    }
};