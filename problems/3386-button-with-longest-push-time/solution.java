class Solution {
    public int buttonWithLongestTime(int[][] events) {
        int longestTime = events[0][1];
        int longestButton = events[0][0];
        for (int i = 1; i < events.length; i++) {
            int time = events[i][1] - events[i - 1][1];
            if (time > longestTime) {
                longestTime = time;
                longestButton = events[i][0];
            } else if (time == longestTime && events[i][0] < longestButton) {
                longestButton = events[i][0];
            }
        }
        return longestButton;
    }
}