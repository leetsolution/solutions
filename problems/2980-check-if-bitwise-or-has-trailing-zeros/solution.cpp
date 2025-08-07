class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int even_count = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                even_count++;
            }
        }
        return even_count >= 2;
    }
};