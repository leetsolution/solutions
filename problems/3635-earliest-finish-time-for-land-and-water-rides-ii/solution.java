class Solution {
    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        int minFinishTime = Integer.MAX_VALUE;
        for (int i = 0; i < landStartTime.length; i++) {
            for (int j = 0; j < waterStartTime.length; j++) {
                int landFinishTime = landStartTime[i] + landDuration[i];
                int waterFinishTime = waterStartTime[j] + waterDuration[j];

                int finishTimeLandFirst = Math.max(landFinishTime, waterStartTime[j]);
                finishTimeLandFirst += waterDuration[j];

                int waterFinishTimeFirst = Math.max(waterFinishTime, landStartTime[i]);
                waterFinishTimeFirst += landDuration[i];

                minFinishTime = Math.min(minFinishTime, Math.min(finishTimeLandFirst, waterFinishTimeFirst));
            }
        }
        return minFinishTime;
    }
}