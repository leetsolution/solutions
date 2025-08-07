    class Solution {
        public long earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
            long minFinishTime = Long.MAX_VALUE;

            for (int i = 0; i < landStartTime.length; i++) {
                for (int j = 0; j < waterStartTime.length; j++) {
                    // Plan A: Land then Water
                    long landFinishTime = (long) landStartTime[i] + landDuration[i];
                    long waterStartTimeA = Math.max(landFinishTime, (long) waterStartTime[j]);
                    long finishTimeA = waterStartTimeA + waterDuration[j];
                    minFinishTime = Math.min(minFinishTime, finishTimeA);

                    //Plan B: Water then Land
                    long waterFinishTime = (long) waterStartTime[j] + waterDuration[j];
                    long landStartTimeB = Math.max(waterFinishTime, (long) landStartTime[i]);
                    long finishTimeB = landStartTimeB + landDuration[i];
                    minFinishTime = Math.min(minFinishTime, finishTimeB);

                }
            }
            return minFinishTime;
        }
    }
