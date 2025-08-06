class Solution {
    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
    class Solution {
        public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
            int minFinishTime = Integer.MAX_VALUE;

            for (int i = 0; i < landStartTime.length; i++) {
                for (int j = 0; j < waterStartTime.length; j++) {
                    // Plan A: Land ride then Water ride
                    int finishTimeA = landStartTime[i] + landDuration[i];
                    finishTimeA = Math.max(finishTimeA, waterStartTime[j]) + waterDuration[j];
                    minFinishTime = Math.min(minFinishTime, finishTimeA);

                    //Plan B: Water ride then Land ride
                    int finishTimeB = waterStartTime[j] + waterDuration[j];
                    finishTimeB = Math.max(finishTimeB, landStartTime[i]) + landDuration[i];
                    minFinishTime = Math.min(minFinishTime, finishTimeB);
                }
            }
            return minFinishTime;
        }
    }
}