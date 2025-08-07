class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count = 0;
        unordered_map<int, int> dominoMap;
        for (auto& domino : dominoes) {
            int a = domino[0];
            int b = domino[1];
            if (a > b) {
                swap(a, b);
            }
            int dominoKey = a * 10 + b;
            count += dominoMap[dominoKey];
            dominoMap[dominoKey]++;
        }
        return count;
    }
};