class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> visited(n, false);
        int current = 0;
        int turn = 1;
        visited[0] = true;
        while (true) {
            int next = (current + turn * k) % n;
            if (visited[next]) {
                break;
            }
            visited[next] = true;
            current = next;
            turn++;
        }
        vector<int> losers;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                losers.push_back(i + 1);
            }
        }
        return losers;
    }
};