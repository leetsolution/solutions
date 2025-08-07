bool containsPattern(int* arr, int arrSize, int m, int k) {
    if (arrSize < m * k) {
        return false;
    }

    for (int i = 0; i <= arrSize - m * k; i++) {
        int count = 1;
        for (int j = i + m; j <= arrSize - m; j += m) {
            int match = 1;
            for (int l = 0; l < m; l++) {
                if (arr[i + l] != arr[j + l]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                count++;
            } else {
                break;
            }
        }
        if (count >= k) {
            return true;
        }
    }

    return false;
}