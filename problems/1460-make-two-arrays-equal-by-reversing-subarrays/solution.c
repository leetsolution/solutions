bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {
    int counts[1001] = {0};
    for (int i = 0; i < targetSize; i++) {
        counts[target[i]]++;
        counts[arr[i]]--;
    }
    for (int i = 1; i <= 1000; i++) {
        if (counts[i] != 0) {
            return false;
        }
    }
    return true;
}