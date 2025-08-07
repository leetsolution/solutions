class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiagonal = 0;
        int maxArea = 0;
        for (const auto& dimension : dimensions) {
            int length = dimension[0];
            int width = dimension[1];
            double diagonal = sqrt(length * length + width * width);
            int area = length * width;
            if (diagonal > maxDiagonal) {
                maxDiagonal = diagonal;
                maxArea = area;
            } else if (diagonal == maxDiagonal) {
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};