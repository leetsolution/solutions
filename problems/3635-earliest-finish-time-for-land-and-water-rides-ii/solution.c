int earliestFinishTime(int* landStartTime, int landStartTimeSize, int* landDuration, int landDurationSize, int* waterStartTime, int waterStartTimeSize, int* waterDuration, int waterDurationSize) {
    int min_finish_time = -1;

    for (int i = 0; i < landStartTimeSize; i++) {
        for (int j = 0; j < waterStartTimeSize; j++) {
            int land_start = landStartTime[i];
            int land_end = land_start + landDuration[i];
            int water_start = (land_end > waterStartTime[j]) ? land_end : waterStartTime[j];
            int water_end = water_start + waterDuration[j];

            if (min_finish_time == -1 || water_end < min_finish_time) {
                min_finish_time = water_end;
            }

            land_start = (water_end > landStartTime[i]) ? water_end : landStartTime[i];
            land_end = land_start + landDuration[i];
             if (min_finish_time == -1 || land_end < min_finish_time) {
                min_finish_time = land_end;
            }

            water_start = waterStartTime[j];
            int water_end_first = water_start + waterDuration[j];
            land_start = (water_end_first > landStartTime[i]) ? water_end_first : landStartTime[i];
            land_end = land_start + landDuration[i];
             if (min_finish_time == -1 || land_end < min_finish_time) {
                min_finish_time = land_end;
            }

        }
    }

    return min_finish_time;
}