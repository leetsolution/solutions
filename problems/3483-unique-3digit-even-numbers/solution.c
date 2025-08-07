int totalNumbers(int* digits, int digitsSize) {
    int count = 0;
    int freq[10] = {0};
    for (int i = 0; i < digitsSize; i++) {
        freq[digits[i]]++;
    }
    int nums[1000] = {0};
    for (int i = 100; i <= 999; i += 2) {
        int tempFreq[10] = {0};
        int num = i;
        int digit3 = num % 10;
        num /= 10;
        int digit2 = num % 10;
        num /= 10;
        int digit1 = num % 10;
        tempFreq[digit1]++;
        tempFreq[digit2]++;
        tempFreq[digit3]++;
        if (digit1 == 0) {
            continue;
        }
        if (freq[digit1] >= tempFreq[digit1] &&
            freq[digit2] >= tempFreq[digit2] &&
            freq[digit3] >= tempFreq[digit3]) {
                if(nums[i] == 0){
                    count++;
                    nums[i] = 1;
                }
        }
    }
    return count;
}