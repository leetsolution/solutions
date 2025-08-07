#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    // Sample test case
    int landStartTime[] = {1, 5};
    int landDuration[] = {4, 2};
    int waterStartTime[] = {3, 6};
    int waterDuration[] = {5, 1};
    int landStartTimeSize = sizeof(landStartTime) / sizeof(landStartTime[0]);
    int waterStartTimeSize = sizeof(waterStartTime) / sizeof(waterStartTime[0]);
    int result = earliestFinishTime(landStartTime, landStartTimeSize, landDuration, waterStartTime, waterStartTimeSize, waterDuration);
    printf("Earliest finish time: %d\n", result);
    return 0;
}

int earliestFinishTime(int* landStartTime, int landStartTimeSize, int* landDuration, int* waterStartTime, int waterStartTimeSize, int* waterDuration) {
    int minFinishTime = INT_MAX;
    for (int i = 0; i < landStartTimeSize; i++) {
        for (int j = 0; j < waterStartTimeSize; j++) {
            // Land then Water
            int landFinishTime = landStartTime[i] + landDuration[i];
            int waterStartTime_ = waterStartTime[j];
            int waterFinishTime = (landFinishTime > waterStartTime_) ? landFinishTime + waterDuration[j] : waterStartTime_ + waterDuration[j];
            minFinishTime = min(minFinishTime, waterFinishTime);

            // Water then Land
            int waterFinishTime_ = waterStartTime[j] + waterDuration[j];
            int landStartTime_ = landStartTime[i];
            int landFinishTime_ = (waterFinishTime_ > landStartTime_) ? waterFinishTime_ + landDuration[i] : landStartTime_ + landDuration[i];
            minFinishTime = min(minFinishTime, landFinishTime_);
        }
    }
    return minFinishTime;
}