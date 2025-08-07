int findKthPositive(int* arr, int arrSize, int k) {
    int count = 0;
    int i = 1;
    int j = 0;
    while (count < k) {
        if (j < arrSize && arr[j] == i) {
            j++;
        } else {
            count++;
        }
        if (count == k) {
            return i;
        }
        i++;
    }
    return i;
}