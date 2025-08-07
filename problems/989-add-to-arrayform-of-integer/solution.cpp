class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        int n = num.size();
        int i = n - 1;
        int carry = 0;
        while (i >= 0 || k > 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) {
                sum += num[i];
                i--;
            }
            if (k > 0) {
                sum += k % 10;
                k /= 10;
            }
            carry = sum / 10;
            res.push_back(sum % 10);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};