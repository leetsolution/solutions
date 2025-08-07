class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }

    int maxLength(vector<int>& nums) {
        int maxLen = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                long long prod = 1;
                int currGcd = nums[i];
                int currLcm = nums[i];
                for (int k = i; k <= j; ++k) {
                    prod *= nums[k];
                    currGcd = gcd(currGcd, nums[k]);
                    currLcm = lcm(currLcm, nums[k]);
                }

                if (prod == (long long)currLcm * currGcd) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};