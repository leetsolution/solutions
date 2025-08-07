class Solution {
    public int hardestWorker(int n, int[][] logs) {
        int longestTime = logs[0][1];
        int hardestWorkerId = logs[0][0];
        int prevLeaveTime = logs[0][1];

        for (int i = 1; i < logs.length; i++) {
            int currentTime = logs[i][1] - prevLeaveTime;
            if (currentTime > longestTime) {
                longestTime = currentTime;
                hardestWorkerId = logs[i][0];
            } else if (currentTime == longestTime) {
                hardestWorkerId = Math.min(hardestWorkerId, logs[i][0]);
            }
            prevLeaveTime = logs[i][1];
        }

        if(longestTime < logs[0][1]){
            longestTime = logs[0][1];
            hardestWorkerId = logs[0][0];
        }

        return hardestWorkerId;
    }
}