class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        std::map<int, int> mergedItems;
        for (auto& item : items1) {
            mergedItems[item[0]] += item[1];
        }
        for (auto& item : items2) {
            mergedItems[item[0]] += item[1];
        }
        vector<vector<int>> result;
        for (auto& item : mergedItems) {
            result.push_back({item.first, item.second});
        }
        return result;
    }
};