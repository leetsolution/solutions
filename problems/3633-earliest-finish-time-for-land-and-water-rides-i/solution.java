class Solution {
    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        int minFinishTime = Integer.MAX_VALUE;

        for (int i = 0; i < landStartTime.length; i++) {
            for (int j = 0; j < waterStartTime.length; j++) {
                int landFinishTime = landStartTime[i] + landDuration[i];
                int waterFinishTime = waterStartTime[j] + waterDuration[j];

                int finishTimeLandWater = Math.max(landFinishTime, waterStartTime[j]) + waterDuration[j];
                int finishTimeWaterLand = Math.max(waterFinishTime, landStartTime[i]) + landDuration[i];

                finishTimeLandWater = Math.max(landStartTime[i], landStartTime[i]) + landDuration[i];
                finishTimeLandWater = Math.max(finishTimeLandWater, waterStartTime[j]);
                finishTimeLandWater += waterDuration[j];
                
                finishTimeWaterLand = Math.max(waterStartTime[j], waterStartTime[j]) + waterDuration[j];
                finishTimeWaterLand = Math.max(finishTimeWaterLand, landStartTime[i]);
                finishTimeWaterLand += landDuration[i];
                

                int landStart = Math.max(landStartTime[i], landStartTime[i]);
                int waterStart = Math.max(waterStartTime[j], waterStartTime[j]);
                
                int finishTime1 = Math.max(landStart + landDuration[i], waterStartTime[j]) + waterDuration[j];
                int finishTime2 = Math.max(waterStart + waterDuration[j], landStartTime[i]) + landDuration[i];


                minFinishTime = Math.min(minFinishTime, Math.min(finishTime1, finishTime2));
            }
        }

        return minFinishTime;
    }
}