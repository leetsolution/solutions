class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> visited;
        visited.insert({0, 0});
        int x = 0, y = 0;
        for (char c : path) {
            if (c == 'N') y++;
            else if (c == 'S') y--;
            else if (c == 'E') x++;
            else x--;
            if (visited.count({x, y})) return true;
            visited.insert({x, y});
        }
        return false;
    }
};