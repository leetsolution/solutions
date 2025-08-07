class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> arr;
        while (!nums.empty()) {
            int min1 = nums[0], min1_idx = 0;
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] < min1) {
                    min1 = nums[i];
                    min1_idx = i;
                }
            }
            nums.erase(nums.begin() + min1_idx);

            int min2 = nums[0], min2_idx = 0;
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] < min2) {
                    min2 = nums[i];
                    min2_idx = i;
                }
            }
            nums.erase(nums.begin() + min2_idx);

            arr.push_back(min2);
            arr.push_back(min1);
        }
        return arr;
    }
};