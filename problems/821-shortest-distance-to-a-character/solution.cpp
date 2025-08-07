class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> result;
        vector<int> indices;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c) {
                indices.push_back(i);
            }
        }
        for (int i = 0; i < s.length(); i++) {
            int minDistance = INT_MAX;
            for (int index : indices) {
                int distance = abs(i - index);
                if (distance < minDistance) {
                    minDistance = distance;
                }
            }
            result.push_back(minDistance);
        }
        return result;
    }
};