int findLucky(int* arr, int arrSize) {
    int counts[501] = {0};
    for (int i = 0; i < arrSize; i++) {
        counts[arr[i]]++;
    }
    int maxLucky = -1;
    for (int i = 1; i <= 500; i++) {
        if (counts[i] == i) {
            maxLucky = i;
        }
    }
    return maxLucky;
}