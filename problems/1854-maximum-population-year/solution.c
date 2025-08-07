int maximumPopulation(int** logs, int logsSize, int* logsColSize) {
    int years[101] = {0};
    for (int i = 0; i < logsSize; i++) {
        for (int year = logs[i][0]; year < logs[i][1]; year++) {
            years[year - 1950]++;
        }
    }
    int maxPop = 0;
    int maxYear = 1950;
    for (int i = 0; i < 101; i++) {
        if (years[i] > maxPop) {
            maxPop = years[i];
            maxYear = 1950 + i;
        }
    }
    return maxYear;
}