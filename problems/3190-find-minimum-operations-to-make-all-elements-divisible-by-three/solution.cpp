class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums) {
            sum = (sum + num % 3) % 3;
        }
        if (sum == 0) {
            return 0;
        } else if (sum == 1) {
            int count1 = 0;
            int count2 = 0;
            for (int num : nums) {
                if (num % 3 == 1) {
                    count1++;
                } else if (num % 3 == 2) {
                    count2++;
                }
            }
            if (count1 > 0) {
                return 1;
            } else {
                return 2;
            }
        } else {
            int count1 = 0;
            int count2 = 0;
            for (int num : nums) {
                if (num % 3 == 1) {
                    count1++;
                } else if (num % 3 == 2) {
                    count2++;
                }
            }
            if (count2 > 0) {
                return 1;
            } else {
                return 2;
            }
        }
    }
};