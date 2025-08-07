class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int maxTime = events[0][1];
        int buttonIndex = events[0][0];

        for (int i = 1; i < events.size(); ++i) {
            int timeDiff = events[i][1] - events[i - 1][1];
            if (timeDiff > maxTime) {
                maxTime = timeDiff;
                buttonIndex = events[i][0];
            }
        }

        return buttonIndex;
    }
};