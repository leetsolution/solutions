class Solution {
public:
    int maxSum(vector<int>& nums) {
        int max_sum = -1;
        vector<int> max_digit(10, -1);

        for (int num : nums) {
            int temp = num;
            int largest_digit = 0;
            while (temp > 0) {
                largest_digit = max(largest_digit, temp % 10);
                temp /= 10;
            }

            if (max_digit[largest_digit] != -1) {
                max_sum = max(max_sum, num + max_digit[largest_digit]);
            }

            max_digit[largest_digit] = max(max_digit[largest_digit], num);
        }

        return max_sum;
    }
};