int largestInteger(int num) {
    int digits[10] = {0};
    int odd[5] = {0};
    int even[5] = {0};
    int oddCount = 0;
    int evenCount = 0;
    int temp = num;
    int i = 0;
    while (temp > 0) {
        int digit = temp % 10;
        digits[i++] = digit;
        if (digit % 2 == 0) {
            even[evenCount++] = digit;
        } else {
            odd[oddCount++] = digit;
        }
        temp /= 10;
    }
    int result = 0;
    int multiplier = 1;
    for (i = 0; i < 10; i++) {
        int digit = digits[i];
        if (digit % 2 == 0) {
            int j = 0;
            int maxEven = -1;
            int maxEvenIndex = -1;
            for (j = 0; j < evenCount; j++) {
                if (even[j] > maxEven) {
                    maxEven = even[j];
                }
            }
            result += maxEven * multiplier;
            for (j = 0; j < evenCount; j++) {
                if (even[j] == maxEven) {
                    even[j] = -1;
                    break;
                }
            }
            evenCount--;

        } else {
            int j = 0;
            int maxOdd = -1;
            for (j = 0; j < oddCount; j++) {
                if (odd[j] > maxOdd) {
                    maxOdd = odd[j];
                }
            }
            result += maxOdd * multiplier;
            for (j = 0; j < oddCount; j++) {
                if (odd[j] == maxOdd) {
                    odd[j] = -1;
                    break;
                }
            }
            oddCount--;
        }
        multiplier *= 10;

    }
    return result;
}