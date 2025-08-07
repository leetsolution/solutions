class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> result;
        vector<pair<int, vector<int>>> distances;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int distance = abs(i - rCenter) + abs(j - cCenter);
                distances.push_back({distance, {i, j}});
            }
        }

        sort(distances.begin(), distances.end());

        for (const auto& p : distances) {
            result.push_back(p.second);
        }

        return result;
    }
};