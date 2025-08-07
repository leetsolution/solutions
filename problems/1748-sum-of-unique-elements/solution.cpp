class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> counts(101, 0);
        for (int num : nums) {
            counts[num]++;
        }
        int sum = 0;
        for (int i = 1; i <= 100; i++) {
            if (counts[i] == 1) {
                sum += i;
            }
        }
        return sum;
    }
};