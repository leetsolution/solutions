class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int prev = (i - 1 + n) % n;
            int next = (i + 1) % n;
            if (colors[prev] != colors[i] && colors[next] != colors[i]) {
                count++;
            }
        }
        return count;
    }
};