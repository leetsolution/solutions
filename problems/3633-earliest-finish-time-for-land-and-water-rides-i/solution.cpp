class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minFinishTime = -1;

        for (int i = 0; i < landStartTime.size(); ++i) {
            for (int j = 0; j < waterStartTime.size(); ++j) {
                // Land then Water
                int landFinishTime = landStartTime[i] + landDuration[i];
                int waterFinishTime = max(landFinishTime, waterStartTime[j]) + waterDuration[j];
                if (minFinishTime == -1 || waterFinishTime < minFinishTime) {
                    minFinishTime = waterFinishTime;
                }

                // Water then Land
                int waterFinishTime2 = waterStartTime[j] + waterDuration[j];
                int landFinishTime2 = max(waterFinishTime2, landStartTime[i]) + landDuration[i];
                if (minFinishTime == -1 || landFinishTime2 < minFinishTime) {
                    minFinishTime = landFinishTime2;
                }
            }
        }
        return minFinishTime;
    }
};