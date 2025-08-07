class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int diff = 0;
        for (int i = 0; i < s.length(); i++) {
            int s_index = i;
            int t_index = t.find(s[i]);
            diff += abs(s_index - t_index);
        }
        return diff;
    }
};