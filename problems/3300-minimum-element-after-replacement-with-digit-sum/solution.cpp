class Solution {
public:
    int minElement(vector<int>& nums) {
        vector<int> digitSums;
        for (int num : nums) {
            int sum = 0;
            int temp = num;
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            digitSums.push_back(sum);
        }

        int minVal = digitSums[0];
        for (int i = 1; i < digitSums.size(); ++i) {
            minVal = min(minVal, digitSums[i]);
        }

        return minVal;
    }
};