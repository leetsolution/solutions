class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n);
        int start = 1;
        for (int i = 0; i < n - (n % 2); i += 2) {
            result[i] = start;
            result[i + 1] = -start;
            start++;
        }
        if (n % 2 != 0) {
            result[n - 1] = 0;
        }
        return result;
    }
};