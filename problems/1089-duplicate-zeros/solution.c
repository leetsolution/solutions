void duplicateZeros(int* arr, int arrSize) {
    int zeros = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == 0) {
            zeros++;
        }
    }

    int i = arrSize - 1;
    int j = arrSize + zeros - 1;

    while (i != j) {
        if (arr[i] == 0) {
            if (j < arrSize) {
                arr[j] = 0;
            }
            j--;
            if (j < arrSize) {
                arr[j] = 0;
            }
        } else {
            if (j < arrSize) {
                arr[j] = arr[i];
            }
        }
        i--;
        j--;
    }
}