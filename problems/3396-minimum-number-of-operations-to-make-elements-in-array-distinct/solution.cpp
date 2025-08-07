class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int operations = 0;
        vector<int> current_nums = nums;
        while (true) {
            unordered_set<int> distinct_elements;
            bool all_distinct = true;
            for (int num : current_nums) {
                if (distinct_elements.count(num)) {
                    all_distinct = false;
                    break;
                }
                distinct_elements.insert(num);
            }
            if (all_distinct) {
                return operations;
            }
            operations++;
            vector<int> next_nums;
            for (int i = 3; i < current_nums.size(); ++i) {
                next_nums.push_back(current_nums[i]);
            }
            current_nums = next_nums;
            if (current_nums.size() == 0) return operations;
        }
    }
};