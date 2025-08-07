class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumAlice = 0;
        int sumBob = 0;
        unordered_set<int> s;
        for (int x : aliceSizes) sumAlice += x;
        for (int x : bobSizes) {
            sumBob += x;
            s.insert(x);
        }
        for (int x : aliceSizes) {
            int y = (sumBob - sumAlice + 2 * x) / 2;
            if (s.count(y)) return {x, y};
        }
        return {};
    }
};