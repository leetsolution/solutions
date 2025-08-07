long long pickGifts(int* gifts, int giftsSize, int k) {
    long long totalGifts = 0;
    int i, maxIndex;
    for (i = 0; i < k; i++) {
        maxIndex = 0;
        for (int j = 1; j < giftsSize; j++) {
            if (gifts[j] > gifts[maxIndex]) {
                maxIndex = j;
            }
        }
        int original = gifts[maxIndex];
        gifts[maxIndex] = (int)sqrt(original);
    }
    for (i = 0; i < giftsSize; i++) {
        totalGifts += gifts[i];
    }
    return totalGifts;
}