class Solution {
    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        int minFinishTime = Integer.MAX_VALUE;
        for (int i = 0; i < landStartTime.length; i++) {
            for (int j = 0; j < waterStartTime.length; j++) {
                // Plan A: Land then Water
                int landFinishTime = landStartTime[i] + landDuration[i];
                int waterStartTimeA = Math.max(landFinishTime, waterStartTime[j]);
                int finishTimeA = waterStartTimeA + waterDuration[j];
                minFinishTime = Math.min(minFinishTime, finishTimeA);

                // Plan B: Water then Land
                int waterFinishTime = waterStartTime[j] + waterDuration[j];
                int landStartTimeB = Math.max(waterFinishTime, landStartTime[i]);
                int finishTimeB = landStartTimeB + landDuration[i];
                minFinishTime = Math.min(minFinishTime, finishTimeB);
            }
        }
        return minFinishTime;
    }
}