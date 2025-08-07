bool canThreePartsEqualSum(int* arr, int arrSize) {
    int totalSum = 0;
    for (int i = 0; i < arrSize; i++) {
        totalSum += arr[i];
    }

    if (totalSum % 3 != 0) {
        return false;
    }

    int targetSum = totalSum / 3;
    int currentSum = 0;
    int count = 0;
    for (int i = 0; i < arrSize; i++) {
        currentSum += arr[i];
        if (currentSum == targetSum) {
            count++;
            currentSum = 0;
        }
    }

    return count >= 3;
}