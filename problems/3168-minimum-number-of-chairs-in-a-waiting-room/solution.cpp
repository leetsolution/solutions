class Solution {
public:
    int minimumChairs(string s) {
        int chairs = 0;
        int maxChairs = 0;
        for (char c : s) {
            if (c == 'E') {
                chairs++;
                maxChairs = max(maxChairs, chairs);
            } else {
                chairs--;
            }
        }
        return maxChairs;
    }
};