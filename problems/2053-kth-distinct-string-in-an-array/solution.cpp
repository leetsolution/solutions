class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> counts;
        for (const string& s : arr) {
            counts[s]++;
        }

        vector<string> distinct_strings;
        for (const string& s : arr) {
            if (counts[s] == 1) {
                distinct_strings.push_back(s);
            }
        }

        if (distinct_strings.size() < k) {
            return "";
        } else {
            return distinct_strings[k - 1];
        }
    }
};