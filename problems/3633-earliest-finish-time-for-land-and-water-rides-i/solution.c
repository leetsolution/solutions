#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static int min(int a, int b) {
    return a < b ? a : b;
}

int earliestFinishTime(int* landStartTime, int landStartTimeSize, int* landDuration, int landDurationSize, int* waterStartTime, int waterStartTimeSize, int* waterDuration, int waterDurationSize) {
    int minFinishTime = INT_MAX;
    for (int i = 0; i < landStartTimeSize; i++) {
        for (int j = 0; j < waterStartTimeSize; j++) {
            // Land then Water
            int landFinishTime = landStartTime[i] + landDuration[i];
            int waterStartTime_ = (landFinishTime > waterStartTime[j]) ? landFinishTime : waterStartTime[j];
            int finishTime = waterStartTime_ + waterDuration[j];
            minFinishTime = min(minFinishTime, finishTime);

            // Water then Land
            int waterFinishTime = waterStartTime[j] + waterDuration[j];
            int landStartTime_ = (waterFinishTime > landStartTime[i]) ? waterFinishTime : landStartTime[i];
            finishTime = landStartTime_ + landDuration[i];
            minFinishTime = min(minFinishTime, finishTime);
        }
    }
    return minFinishTime;
}