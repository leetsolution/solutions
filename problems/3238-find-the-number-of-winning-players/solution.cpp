class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int wins = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> colorCounts;
            for (const auto& p : pick) {
                if (p[0] == i) {
                    colorCounts[p[1]]++;
                }
            }
            bool won = false;
            for (const auto& [color, count] : colorCounts) {
                if (count > i) {
                    won = true;
                    break;
                }
            }
            if (won) {
                wins++;
            }
        }
        return wins;
    }
};