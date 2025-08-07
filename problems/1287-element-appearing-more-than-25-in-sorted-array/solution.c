int findSpecialInteger(int* arr, int arrSize) {
    int threshold = arrSize / 4;
    int count = 1;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] == arr[i - 1]) {
            count++;
            if (count > threshold) {
                return arr[i];
            }
        } else {
            count = 1;
        }
    }
    return arr[0];
}