class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int count = 0;
        if (nums.size() < 2) return 0;
        int target = nums[0] + nums[1];
        for (int i = 0; i < nums.size() - 1; i += 2) {
            if (nums[i] + nums[i + 1] == target) {
                count++;
            } else {
                break;
            }
        }
        return count;
    }
};