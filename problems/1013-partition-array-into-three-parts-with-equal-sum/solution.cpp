class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for (int num : arr) {
            sum += num;
        }

        if (sum % 3 != 0) {
            return false;
        }

        int target = sum / 3;
        int currentSum = 0;
        int count = 0;

        for (int i = 0; i < arr.size(); i++) {
            currentSum += arr[i];
            if (currentSum == target) {
                count++;
                currentSum = 0;
            }
        }

        return count >= 3;
    }
};