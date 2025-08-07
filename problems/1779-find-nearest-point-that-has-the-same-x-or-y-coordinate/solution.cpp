class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minDistance = INT_MAX;
        int index = -1;
        for (int i = 0; i < points.size(); ++i) {
            if (points[i][0] == x || points[i][1] == y) {
                int distance = abs(x - points[i][0]) + abs(y - points[i][1]);
                if (distance < minDistance) {
                    minDistance = distance;
                    index = i;
                }
            }
        }
        return index;
    }
};