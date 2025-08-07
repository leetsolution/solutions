class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> starts;
        for (const auto& path : paths) {
            starts.insert(path[0]);
        }

        for (const auto& path : paths) {
            if (starts.find(path[1]) == starts.end()) {
                return path[1];
            }
        }

        return "";
    }
};