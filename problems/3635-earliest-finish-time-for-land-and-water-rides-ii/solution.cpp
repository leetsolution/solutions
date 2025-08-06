class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
    #include <vector>
    #include <algorithm>

    using namespace std;

    long long earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        long long minFinishTime = -1;

        for (int i = 0; i < landStartTime.size(); ++i) {
            for (int j = 0; j < waterStartTime.size(); ++j) {
                long long finishTime1 = landStartTime[i] + landDuration[i];
                finishTime1 = max(finishTime1, (long long)waterStartTime[j]) + waterDuration[j];

                long long finishTime2 = waterStartTime[j] + waterDuration[j];
                finishTime2 = max(finishTime2, (long long)landStartTime[i]) + landDuration[i];

                long long curFinishTime = min(finishTime1, finishTime2);
                if (minFinishTime == -1 || curFinishTime < minFinishTime) {
                    minFinishTime = curFinishTime;
                }
            }
        }
        return minFinishTime;
    }
};