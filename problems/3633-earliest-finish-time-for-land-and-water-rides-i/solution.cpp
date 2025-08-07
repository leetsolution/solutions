class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minFinishTime = INT_MAX;
        for (int i = 0; i < landStartTime.size(); ++i) {
            for (int j = 0; j < waterStartTime.size(); ++j) {
                int landFinishTime = landStartTime[i] + landDuration[i];
                int waterFinishTime = waterStartTime[j] + waterDuration[j];

                int finishTimeLandWater = max(landFinishTime, waterStartTime[j]);
                finishTimeLandWater += waterDuration[j];

                int finishTimeWaterLand = max(waterFinishTime, landStartTime[i]);
                finishTimeWaterLand += landDuration[i];
                
                minFinishTime = min(minFinishTime, min(finishTimeLandWater, finishTimeWaterLand));
            }
        }
        return minFinishTime;
    }
};