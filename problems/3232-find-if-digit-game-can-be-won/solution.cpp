class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum = 0;
        int singleDigitSum = 0;
        int doubleDigitSum = 0;
        for (int num : nums) {
            sum += num;
            if (num < 10) {
                singleDigitSum += num;
            } else {
                doubleDigitSum += num;
            }
        }
        if (singleDigitSum > sum - singleDigitSum) {
            return true;
        }
        if (doubleDigitSum > sum - doubleDigitSum) {
            return true;
        }
        return false;
    }
};