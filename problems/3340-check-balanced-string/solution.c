bool isBalanced(char* num) {
    int evenSum = 0;
    int oddSum = 0;
    int i = 0;
    while (num[i] != '\0') {
        if (i % 2 == 0) {
            evenSum += (num[i] - '0');
        } else {
            oddSum += (num[i] - '0');
        }
        i++;
    }
    return evenSum == oddSum;
}