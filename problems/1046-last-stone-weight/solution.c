int lastStoneWeight(int* stones, int stonesSize) {
    while (stonesSize > 1) {
        int max1 = 0, max2 = 0, idx1 = -1, idx2 = -1;
        for (int i = 0; i < stonesSize; i++) {
            if (stones[i] > max1) {
                max2 = max1;
                idx2 = idx1;
                max1 = stones[i];
                idx1 = i;
            } else if (stones[i] > max2) {
                max2 = stones[i];
                idx2 = i;
            }
        }

        if (max1 == max2) {
            if (idx1 < idx2) {
                stones[idx2] = stones[stonesSize - 1];
                stones[idx1] = stones[stonesSize - 2];
            } else {
                stones[idx1] = stones[stonesSize - 1];
                stones[idx2] = stones[stonesSize - 2];
            }
            stonesSize -= 2;
        } else {
            stones[idx1] = max1 - max2;
            if (idx2 < stonesSize - 1) {
                stones[idx2] = stones[stonesSize - 1];
            }
            stonesSize--;
        }
    }

    if (stonesSize == 0) {
        return 0;
    } else {
        return stones[0];
    }
}