class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long res = 0;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (l == r) {
                res += nums[l];
                break;
            }
            long long num1 = nums[l];
            long long num2 = nums[r];
            string s1 = to_string(num1);
            string s2 = to_string(num2);
            string s = s1 + s2;
            res += stoll(s);
            l++;
            r--;
        }
        return res;
    }
};