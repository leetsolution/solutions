class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int max_element = 0;
        for (int num : nums) {
            max_element = max(max_element, num);
        }
        
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += max_element;
            max_element++;
        }
        
        return sum;
    }
};