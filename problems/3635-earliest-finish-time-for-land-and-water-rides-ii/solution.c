#include <stdlib.h>
#include <limits.h>

int earliestFinishTime(int* landStartTime, int* landDuration, int landSize, int* waterStartTime, int* waterDuration, int waterSize) {
    long long minFinishTime = LLONG_MAX;
    for (int i = 0; i < landSize; i++) {
        for (int j = 0; j < waterSize; j++) {
            // Plan: Land -> Water
            long long finishTimeLandFirst = (long long)landStartTime[i] + landDuration[i];
            long long startTimeWater = (finishTimeLandFirst > waterStartTime[j]) ? finishTimeLandFirst : waterStartTime[j];
            long long finishTimeLandFirstWaterSecond = startTimeWater + waterDuration[j];
            if (finishTimeLandFirstWaterSecond < minFinishTime)
                minFinishTime = finishTimeLandFirstWaterSecond;

            // Plan: Water -> Land
            long long finishTimeWaterFirst = (long long)waterStartTime[j] + waterDuration[j];
            long long startTimeLand = (finishTimeWaterFirst > landStartTime[i]) ? finishTimeWaterFirst : landStartTime[i];
            long long finishTimeWaterFirstLandSecond = startTimeLand + landDuration[i];
            if (finishTimeWaterFirstLandSecond < minFinishTime)
                minFinishTime = finishTimeWaterFirstLandSecond;
        }
    }
    return (int)minFinishTime;
}
