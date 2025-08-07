#include <vector>

class Solution {
public:
    std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;
        std::vector<int> counts(N + 1, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                counts[grid[i][j]]++;
            }
        }

        std::vector<int> ans(2);
        for (int i = 1; i <= N; ++i) {
            if (counts[i] == 2) {
                ans[0] = i;
            }
            if (counts[i] == 0) {
                ans[1] = i;
            }
        }
        return ans;
    }
};