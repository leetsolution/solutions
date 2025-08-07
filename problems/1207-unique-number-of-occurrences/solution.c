bool uniqueOccurrences(int* arr, int arrSize) {
    int counts[2001] = {0};
    for (int i = 0; i < arrSize; i++) {
        counts[arr[i] + 1000]++;
    }

    int occurrences[1001] = {0};
    for (int i = 0; i < 2001; i++) {
        if (counts[i] > 0) {
            if (occurrences[counts[i]] > 0) {
                return false;
            }
            occurrences[counts[i]] = 1;
        }
    }

    return true;
}