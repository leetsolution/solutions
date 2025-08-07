double trimMean(int* arr, int arrSize) {
    int i, j, temp;
    for (i = 0; i < arrSize - 1; i++) {
        for (j = 0; j < arrSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    int removeCount = arrSize / 20;
    double sum = 0.0;
    for (i = removeCount; i < arrSize - removeCount; i++) {
        sum += arr[i];
    }
    return sum / (arrSize - 2 * removeCount);
}