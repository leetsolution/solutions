class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> count(101, 0);
        for (int num : nums) {
            count[num]++;
        }
        int pairs = 0;
        int leftovers = 0;
        for (int i = 0; i <= 100; i++) {
            pairs += count[i] / 2;
            leftovers += count[i] % 2;
        }
        return {pairs, leftovers};
    }
};