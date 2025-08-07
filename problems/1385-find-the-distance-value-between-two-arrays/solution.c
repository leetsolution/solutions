int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
    int distance = 0;
    for (int i = 0; i < arr1Size; i++) {
        int found = 0;
        for (int j = 0; j < arr2Size; j++) {
            if (abs(arr1[i] - arr2[j]) <= d) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            distance++;
        }
    }
    return distance;
}