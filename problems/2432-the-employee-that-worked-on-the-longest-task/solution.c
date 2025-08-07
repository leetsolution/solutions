int hardestWorker(int n, int** logs, int logsSize, int* logsColSize) {
    int maxTime = logs[0][1];
    int employeeId = logs[0][0];
    int prevTime = 0;
    for (int i = 0; i < logsSize; i++) {
        int currentTime = logs[i][1];
        int currentId = logs[i][0];
        int taskTime = currentTime - prevTime;
        if (taskTime > maxTime) {
            maxTime = taskTime;
            employeeId = currentId;
        } else if (taskTime == maxTime && currentId < employeeId) {
            employeeId = currentId;
        }
        prevTime = currentTime;
    }
    return employeeId;
}