class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> s_freq(26, 0);
        vector<int> target_freq(26, 0);

        for (char c : s) {
            s_freq[c - 'a']++;
        }

        for (char c : target) {
            target_freq[c - 'a']++;
        }

        int result = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (target_freq[i] > 0) {
                if (s_freq[i] == 0) return 0;
                result = min(result, s_freq[i] / target_freq[i]);
            }
        }

        return result;
    }
};