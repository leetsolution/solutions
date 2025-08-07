int winningPlayerCount(int n, int** pick, int pickSize, int* pickColSize) {
    int wins = 0;
    for (int player = 0; player < n; player++) {
        int counts[11] = {0};
        for (int i = 0; i < pickSize; i++) {
            if (pick[i][0] == player) {
                counts[pick[i][1]]++;
            }
        }
        for (int i = 0; i < 11; i++) {
            if (counts[i] > player) {
                wins++;
                break;
            }
        }
    }
    return wins;
}