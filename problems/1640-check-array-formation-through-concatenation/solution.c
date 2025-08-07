bool canFormArray(int* arr, int arrSize, int** pieces, int piecesSize, int* piecesColSize) {
    int i = 0;
    while (i < arrSize) {
        int j;
        for (j = 0; j < piecesSize; j++) {
            if (pieces[j][0] == arr[i]) {
                int k;
                for (k = 0; k < piecesColSize[j]; k++) {
                    if (i + k >= arrSize || pieces[j][k] != arr[i + k]) {
                        return false;
                    }
                }
                i += piecesColSize[j];
                break;
            }
        }
        if (j == piecesSize) {
            return false;
        }
    }
    return true;
}