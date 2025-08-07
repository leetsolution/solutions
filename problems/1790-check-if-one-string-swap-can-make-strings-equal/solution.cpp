class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff_count = 0;
        int first_diff = -1;
        int second_diff = -1;

        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] != s2[i]) {
                diff_count++;
                if (first_diff == -1) {
                    first_diff = i;
                } else if (second_diff == -1) {
                    second_diff = i;
                }
            }
        }

        if (diff_count == 0) {
            return true;
        } else if (diff_count == 2) {
            return (s1[first_diff] == s2[second_diff] && s1[second_diff] == s2[first_diff]);
        } else {
            return false;
        }
    }
};