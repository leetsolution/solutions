class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int longest_prefix_len = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                longest_prefix_len++;
            } else {
                break;
            }
        }

        long long prefix_sum = 0;
        for (int i = 0; i < longest_prefix_len; ++i) {
            prefix_sum += nums[i];
        }

        vector<bool> present(101, false);
        for (int num : nums) {
            present[num] = true;
        }

        int x = prefix_sum;
        while (x <= 100 && present[x]) {
            x++;
        }
        
        while(true){
            bool found = false;
            for(int i=0; i<n; i++){
                if(nums[i] == x){
                    x++;
                    found = true;
                    break;
                }
            }
            if(!found) break;
        }
        
        return x;
    }
};