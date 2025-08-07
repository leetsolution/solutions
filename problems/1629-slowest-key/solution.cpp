class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        int maxDuration = releaseTimes[0];
        char slowest = keysPressed[0];

        for (int i = 1; i < n; ++i) {
            int duration = releaseTimes[i] - releaseTimes[i - 1];
            if (duration > maxDuration) {
                maxDuration = duration;
                slowest = keysPressed[i];
            } else if (duration == maxDuration) {
                slowest = max(slowest, keysPressed[i]);
            }
        }

        return slowest;
    }
};