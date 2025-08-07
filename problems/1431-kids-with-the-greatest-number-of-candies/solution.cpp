class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> result(n);
        int maxCandies = 0;
        for (int candy : candies) {
            maxCandies = max(maxCandies, candy);
        }
        for (int i = 0; i < n; i++) {
            if (candies[i] + extraCandies >= maxCandies) {
                result[i] = true;
            } else {
                result[i] = false;
            }
        }
        return result;
    }
};