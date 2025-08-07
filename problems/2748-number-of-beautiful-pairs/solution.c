int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int countBeautifulPairs(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            int firstDigit = 0;
            int temp = nums[i];
            while (temp >= 10) {
                temp /= 10;
            }
            firstDigit = temp;
            int lastDigit = nums[j] % 10;
            if (gcd(firstDigit, lastDigit) == 1) {
                count++;
            }
        }
    }
    return count;
}