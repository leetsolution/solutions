class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::set<double> averages;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            averages.insert((double)(nums[left] + nums[right]) / 2);
            left++;
            right--;
        }
        return averages.size();
    }
};