class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counts;
        for (int x : arr) {
            counts[x]++;
        }
        unordered_set<int> occurrences;
        for (auto const& [key, val] : counts) {
            if (occurrences.count(val)) {
                return false;
            }
            occurrences.insert(val);
        }
        return true;
    }
};