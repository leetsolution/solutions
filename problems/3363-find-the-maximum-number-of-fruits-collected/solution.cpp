#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int mainDiagonal = 0;
        for (int i = 0; i < n; i++) {
            mainDiagonal += fruits[i][i];
        }
        int topRight = computeTopRight(fruits);
        int bottomLeft = computeBottomLeft(fruits);
        // Subtract bottom-right corner twice
        return mainDiagonal + topRight + bottomLeft - 2 * fruits[n - 1][n - 1];
    }
private:
    int computeTopRight(vector<vector<int>>& fruits) {
        int n = fruits.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][n - 1] = fruits[0][n - 1];
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (x >= y && !(x == n - 1 && y == n - 1)) continue;
                int dirs[3][2] = { {1, -1}, {1, 0}, {1, 1} };
                for (int d = 0; d < 3; d++) {
                    int i = x - dirs[d][0], j = y - dirs[d][1];
                    if (i < 0 || i >= n || j < 0 || j >= n) continue;
                    if (i < j && j < n - 1 - i) continue;
                    dp[x][y] = max(dp[x][y], dp[i][j] + fruits[x][y]);
                }
            }
        }
        return dp[n - 1][n - 1];
    }
    int computeBottomLeft(vector<vector<int>>& fruits) {
        int n = fruits.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[n - 1][0] = fruits[n - 1][0];
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (x <= y && !(x == n - 1 && y == n - 1)) continue;
                int dirs[3][2] = { {-1, 1}, {0, 1}, {1, 1} };
                for (int d = 0; d < 3; d++) {
                    int i = x - dirs[d][0], j = y - dirs[d][1];
                    if (i < 0 || i >= n || j < 0 || j >= n) continue;
                    if (j < i && i < n - 1 - j) continue;
                    dp[x][y] = max(dp[x][y], dp[i][j] + fruits[x][y]);
                }
            }
        }
        return dp[n - 1][n - 1];
    }
};
