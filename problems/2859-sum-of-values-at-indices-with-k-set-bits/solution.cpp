class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int count = 0;
            int num = i;
            while (num > 0) {
                count += (num & 1);
                num >>= 1;
            }
            if (count == k) {
                sum += nums[i];
            }
        }
        return sum;
    }
};