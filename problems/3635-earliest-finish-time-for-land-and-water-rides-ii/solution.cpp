class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
    #include <vector>
    #include <algorithm>

    using namespace std;

    long long earliestFinishTime(vector<long long>& landStartTime, vector<long long>& landDuration, vector<long long>& waterStartTime, vector<long long>& waterDuration) {
        long long minFinishTime = -1;

        for (int i = 0; i < landStartTime.size(); ++i) {
            for (int j = 0; j < waterStartTime.size(); ++j) {
                long long finishTime1 = landStartTime[i] + landDuration[i];
                long long startTime2 = max(finishTime1, waterStartTime[j]);
                long long finishTime2 = startTime2 + waterDuration[j];

                if (minFinishTime == -1 || finishTime2 < minFinishTime) {
                    minFinishTime = finishTime2;
                }
            }
        }

        for (int i = 0; i < waterStartTime.size(); ++i) {
            for (int j = 0; j < landStartTime.size(); ++j) {
                long long finishTime1 = waterStartTime[i] + waterDuration[i];
                long long startTime2 = max(finishTime1, landStartTime[j]);
                long long finishTime2 = startTime2 + landDuration[j];

                if (minFinishTime == -1 || finishTime2 < minFinishTime) {
                    minFinishTime = finishTime2;
                }
            }
        }
        return minFinishTime;
    }
};