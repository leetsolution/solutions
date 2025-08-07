class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        int min_num = INT_MAX;
        for (int i : s1) {
            if (s2.count(i)) {
                min_num = min(min_num, i);
            }
        }
        if (min_num != INT_MAX) return min_num;
        int min1 = *s1.begin();
        int min2 = *s2.begin();
        return min(min1 * 10 + min2, min2 * 10 + min1);
    }
};