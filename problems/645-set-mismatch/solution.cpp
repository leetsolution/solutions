class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
        long long sum = 0;
        long long expectedSum = n * (n + 1) / 2;
        unordered_map<long long, long long> count;
        for (long long num : nums) {
            sum += num;
            count[num]++;
        }
        long long duplicate = 0;
        for (auto const& [key, val] : count) {
            if (val > 1) {
                duplicate = key;
                break;
            }
        }
        long long missing = expectedSum - (sum - duplicate);
        return {duplicate, missing};
    }
};