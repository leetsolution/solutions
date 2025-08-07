class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDist = INT_MAX;
        bool found = false;

        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                found = true;
                int dist1 = abs(i - startIndex);
                int dist2 = n - dist1;
                minDist = min(minDist, min(dist1, dist2));
            }
        }

        if (!found) {
            return -1;
        }

        return minDist;
    }
};