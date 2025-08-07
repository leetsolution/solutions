int numOfUnplacedFruits(int* fruits, int fruitsSize, int* baskets, int basketsSize) {
    int unplaced = 0;
    int used[basketsSize];
    for (int i = 0; i < basketsSize; i++) {
        used[i] = 0;
    }

    for (int i = 0; i < fruitsSize; i++) {
        int placed = 0;
        for (int j = 0; j < basketsSize; j++) {
            if (used[j] == 0 && baskets[j] >= fruits[i]) {
                used[j] = 1;
                placed = 1;
                break;
            }
        }
        if (placed == 0) {
            unplaced++;
        }
    }

    return unplaced;
}