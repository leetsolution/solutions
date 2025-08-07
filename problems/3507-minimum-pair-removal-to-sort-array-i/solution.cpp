class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;
        while (true) {
            bool sorted = true;
            for (int i = 0; i < nums.size() - 1; ++i) {
                if (nums[i] > nums[i + 1]) {
                    sorted = false;
                    break;
                }
            }
            if (sorted) {
                break;
            }

            if (nums.size() < 2) break;

            int minSum = INT_MAX;
            int minIndex = -1;

            for (int i = 0; i < nums.size() - 1; ++i) {
                if (nums[i] + nums[i + 1] < minSum) {
                    minSum = nums[i] + nums[i + 1];
                    minIndex = i;
                }
            }
            
            if (minIndex == -1) break;

            nums[minIndex] = nums[minIndex] + nums[minIndex + 1];
            nums.erase(nums.begin() + minIndex + 1);
            operations++;
        }
        return operations;
    }
};