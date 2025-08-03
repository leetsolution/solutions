class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minFinishTime = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Land then Water
                long long landFinishTime = (long long)landStartTime[i] + landDuration[i];
                long long waterFinishTime = max((long long)waterStartTime[j], landFinishTime) + waterDuration[j];
                minFinishTime = min(minFinishTime, (int)waterFinishTime);

                // Water then Land
                long long waterFinishTime2 = (long long)waterStartTime[j] + waterDuration[j];
                long long landFinishTime2 = max((long long)landStartTime[i], waterFinishTime2) + landDuration[i];
                minFinishTime = min(minFinishTime, (int)landFinishTime2);
            }
        }
        return minFinishTime;
    }
};