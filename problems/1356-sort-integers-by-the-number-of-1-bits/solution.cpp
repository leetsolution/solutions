class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto countSetBits = [](int n) {
            int count = 0;
            while (n > 0) {
                n &= (n - 1);
                count++;
            }
            return count;
        };

        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int bitsA = countSetBits(a);
            int bitsB = countSetBits(b);
            if (bitsA == bitsB) {
                return a < b;
            }
            return bitsA < bitsB;
        });

        return arr;
    }
};