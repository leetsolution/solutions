class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> uniqueCandies;
        for (int candy : candyType) {
            uniqueCandies.insert(candy);
        }
        return min((int)uniqueCandies.size(), candyType.size() / 2);
    }
};