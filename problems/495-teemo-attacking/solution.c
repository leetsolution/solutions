int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    int total_poisoned_time = 0;
    if (timeSeriesSize == 0) return 0;
    total_poisoned_time += duration;
    for (int i = 1; i < timeSeriesSize; i++) {
        if (timeSeries[i] >= timeSeries[i - 1] + duration) {
            total_poisoned_time += duration;
        } else {
            total_poisoned_time += timeSeries[i] - timeSeries[i - 1];
        }
    }
    return total_poisoned_time;
}