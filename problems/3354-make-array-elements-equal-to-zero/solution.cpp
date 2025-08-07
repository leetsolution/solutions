class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int start_index = 0; start_index < n; ++start_index) {
            if (nums[start_index] != 0) continue;

            
            auto check_valid = [&](int start, int dir) -> bool {
                vector<int> temp_nums = nums;
                int curr = start;
                int direction = dir; 

                while (curr >= 0 && curr < n) {
                    if (temp_nums[curr] == 0) {
                        curr += direction;
                    } else {
                        temp_nums[curr]--;
                        direction *= -1;
                        curr += direction;
                    }
                }

                for (int val : temp_nums) {
                    if (val != 0) return false;
                }
                return true;
            };

            
            if (check_valid(start_index, 1)) {
                count++;
            }
            if (check_valid(start_index, -1)) {
                count++;
            }
        }

        return count;
    }
};