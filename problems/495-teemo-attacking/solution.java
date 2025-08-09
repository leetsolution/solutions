class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int totalPoisonedTime = 0;
        if (timeSeries.length == 0) {
            return 0;
        }
        totalPoisonedTime += duration;
        for (int i = 1; i < timeSeries.length; i++) {
            if (timeSeries[i] - timeSeries[i - 1] < duration) {
                totalPoisonedTime += timeSeries[i] - timeSeries[i - 1];
            } else {
                totalPoisonedTime += duration;
            }
        }
        return totalPoisonedTime;
    }
}