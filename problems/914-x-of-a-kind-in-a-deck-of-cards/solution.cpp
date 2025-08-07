class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> counts;
        for (int card : deck) {
            counts[card]++;
        }
        int gcd = counts.begin()->second;
        for (auto const& [key, val] : counts) {
            gcd = std::gcd(gcd, val);
        }
        return gcd > 1;
    }
};