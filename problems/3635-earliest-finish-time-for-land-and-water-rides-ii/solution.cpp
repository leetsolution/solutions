class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minFinishTime = INT_MAX;

        for (int i = 0; i < landStartTime.size(); ++i) {
            for (int j = 0; j < waterStartTime.size(); ++j) {
                int landFinishTime = landStartTime[i] + landDuration[i];
                int waterFinishTime = waterStartTime[j] + waterDuration[j];

                int firstLandThenWater = max(landFinishTime, waterStartTime[j]) + waterDuration[j];
                int firstWaterThenLand = max(waterFinishTime, landStartTime[i]) + landDuration[i];

                minFinishTime = min(minFinishTime, min(firstLandThenWater, firstWaterThenLand));

                firstLandThenWater = max(landStartTime[i],0) + landDuration[i];
                firstWaterThenLand = max(waterStartTime[j],0) + waterDuration[j];

                firstLandThenWater = max(landStartTime[i],0);
                firstWaterThenLand = max(waterStartTime[j],0);

                firstLandThenWater += landDuration[i];
                firstWaterThenLand += waterDuration[j];

                firstLandThenWater = max(firstLandThenWater, waterStartTime[j]) + waterDuration[j];
                firstWaterThenLand = max(firstWaterThenLand, landStartTime[i]) + landDuration[i];

                minFinishTime = min(minFinishTime, min(firstLandThenWater, firstWaterThenLand));
            }
        }

        return minFinishTime;
    }
};