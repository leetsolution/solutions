class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int even_ptr = 0;
        int odd_ptr = 1;
        while (even_ptr < n && odd_ptr < n) {
            if (nums[even_ptr] % 2 == 0) {
                even_ptr += 2;
            } else if (nums[odd_ptr] % 2 != 0) {
                odd_ptr += 2;
            } else {
                swap(nums[even_ptr], nums[odd_ptr]);
                even_ptr += 2;
                odd_ptr += 2;
            }
        }
        return nums;
    }
};