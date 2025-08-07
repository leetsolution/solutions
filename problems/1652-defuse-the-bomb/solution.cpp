class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> decrypted(n, 0);
        if (k == 0) {
            return decrypted;
        }
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            if (k > 0) {
                for (int j = 1; j <= k; ++j) {
                    sum += code[(i + j) % n];
                }
            } else {
                for (int j = 1; j <= -k; ++j) {
                    sum += code[(i - j + n) % n];
                }
            }
            decrypted[i] = sum;
        }
        return decrypted;
    }
};