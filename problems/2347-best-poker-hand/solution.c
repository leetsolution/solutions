char* bestHand(int* ranks, int ranksSize, char* suits, int suitsSize) {
    int flush = 1;
    for (int i = 1; i < suitsSize; i++) {
        if (suits[i] != suits[0]) {
            flush = 0;
            break;
        }
    }

    if (flush) {
        return "Flush";
    }

    int rankCounts[14] = {0};
    for (int i = 0; i < ranksSize; i++) {
        rankCounts[ranks[i]]++;
    }

    int maxCount = 0;
    for (int i = 1; i <= 13; i++) {
        if (rankCounts[i] > maxCount) {
            maxCount = rankCounts[i];
        }
    }

    if (maxCount >= 3) {
        return "Three of a Kind";
    } else if (maxCount == 2) {
        return "Pair";
    } else {
        return "High Card";
    }
}