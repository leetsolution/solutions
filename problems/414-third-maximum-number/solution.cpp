class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (int num : nums) {
            s.insert(num);
        }
        if (s.size() < 3) {
            return *s.rbegin();
        } else {
            auto it = s.rbegin();
            advance(it, 2);
            return *it;
        }
    }
};