char* kthDistinct(char** arr, int arrSize, int k) {
    int counts[arrSize];
    for (int i = 0; i < arrSize; i++) {
        counts[i] = 0;
    }

    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            if (strcmp(arr[i], arr[j]) == 0) {
                counts[i]++;
            }
        }
    }

    int distinct_count = 0;
    for (int i = 0; i < arrSize; i++) {
        if (counts[i] == 1) {
            distinct_count++;
            if (distinct_count == k) {
                return arr[i];
            }
        }
    }

    return "";
}