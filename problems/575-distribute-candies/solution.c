int distributeCandies(int* candyType, int candyTypeSize) {
    int types = 0;
    int count[200001] = {0};
    for (int i = 0; i < candyTypeSize; i++) {
        if (candyType[i] >= -100000 && candyType[i] <= 100000) {
            if (count[candyType[i] + 100000] == 0) {
                types++;
            }
            count[candyType[i] + 100000]++;
        }
    }
    return types > candyTypeSize / 2 ? candyTypeSize / 2 : types;
}