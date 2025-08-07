class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int operations = 0;
        while (true) {
            bool allEqual = true;
            for (int num : nums) {
                if (num != k) {
                    allEqual = false;
                    break;
                }
            }
            if (allEqual) {
                return operations;
            }

            vector<int> greaterThanK;
            for (int num : nums) {
                if (num > k) {
                    greaterThanK.push_back(num);
                }
            }

            if (greaterThanK.empty()) {
                return -1;
            }

            int maxVal = 0;
            for (int num : nums) {
                maxVal = max(maxVal, num);
            }
            
            bool foundValidH = false;
            for (int h = maxVal - 1; h > k; --h) {
                bool isValid = true;
                int firstGreaterThanH = -1;
                for (int num : nums) {
                    if (num > h) {
                        if (firstGreaterThanH == -1) {
                            firstGreaterThanH = num;
                        } else if (num != firstGreaterThanH) {
                            isValid = false;
                            break;
                        }
                    }
                }

                if (isValid) {
                    for (int i = 0; i < nums.size(); ++i) {
                        if (nums[i] > h) {
                            nums[i] = h;
                        }
                    }
                    operations++;
                    foundValidH = true;
                    break;
                }
            }
            
            if (!foundValidH) {
                for (int i = 0; i < nums.size(); ++i) {
                    if (nums[i] > k) {
                        nums[i] = k;
                    }
                }
                operations++;
            }
        }
    }
};