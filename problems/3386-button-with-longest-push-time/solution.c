int buttonWithLongestTime(int** events, int eventsSize, int* eventsColSize) {
    int longestTime = events[0][1];
    int longestButton = events[0][0];
    for (int i = 1; i < eventsSize; i++) {
        int currentTime = events[i][1] - events[i - 1][1];
        if (currentTime > longestTime) {
            longestTime = currentTime;
            longestButton = events[i][0];
        }
    }
    return longestButton;
}