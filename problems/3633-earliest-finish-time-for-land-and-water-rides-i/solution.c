int earliestFinishTime(int* landStartTime, int landStartTimeSize, int* landDuration, int landDurationSize, int* waterStartTime, int waterStartTimeSize, int* waterDuration, int waterDurationSize) {
    int minFinishTime = 1000000000;

    for (int i = 0; i < landStartTimeSize; i++) {
        for (int j = 0; j < waterStartTimeSize; j++) {
            int landStart = landStartTime[i];
            int landEnd = landStart + landDuration[i];
            int waterStart = waterStartTime[j];
            int waterEnd;

            if (landEnd <= waterStart) {
                waterEnd = waterStart + waterDuration[j];
            } else {
                waterEnd = landEnd + waterDuration[j];
            }
            if (waterEnd < minFinishTime) {
                minFinishTime = waterEnd;
            }
        }
    }

    for (int i = 0; i < waterStartTimeSize; i++) {
        for (int j = 0; j < landStartTimeSize; j++) {
            int waterStart = waterStartTime[i];
            int waterEnd = waterStart + waterDuration[i];
            int landStart = landStartTime[j];
            int landEnd;
            if (waterEnd <= landStart) {
                landEnd = landStart + landDuration[j];
            } else {
                landEnd = waterEnd + landDuration[j];
            }

            if (landEnd < minFinishTime) {
                minFinishTime = landEnd;
            }
        }
    }

    return minFinishTime;
}