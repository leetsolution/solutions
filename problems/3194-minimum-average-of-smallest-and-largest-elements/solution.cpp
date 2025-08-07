class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        vector<double> averages;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n / 2; ++i) {
            averages.push_back((double)(nums[i] + nums[n - 1 - i]) / 2.0);
        }
        double min_avg = averages[0];
        for (int i = 1; i < averages.size(); ++i) {
            min_avg = min(min_avg, averages[i]);
        }
        return min_avg;
    }
};