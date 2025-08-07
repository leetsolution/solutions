bool hasGroupsSizeX(int* deck, int deckSize) {
    int counts[10000] = {0};
    for (int i = 0; i < deckSize; i++) {
        counts[deck[i]]++;
    }
    int minCount = 10000;
    for (int i = 0; i < 10000; i++) {
        if (counts[i] > 0) {
            minCount = (minCount == 10000) ? counts[i] : (minCount > counts[i] ? counts[i] : minCount);
        }
    }
    if (minCount < 2) return false;
    for (int i = 2; i <= minCount; i++) {
        bool divisible = true;
        for (int j = 0; j < 10000; j++) {
            if (counts[j] > 0 && counts[j] % i != 0) {
                divisible = false;
                break;
            }
        }
        if (divisible) return true;
    }
    return false;
}