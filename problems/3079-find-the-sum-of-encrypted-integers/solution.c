int sumOfEncryptedInt(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int maxDigit = 0;
        int temp = num;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit > maxDigit) {
                maxDigit = digit;
            }
            temp /= 10;
        }
        int encryptedNum = 0;
        int multiplier = 1;
        temp = num;
        while (temp > 0) {
            int numDigits = 0;
            int temp2 = num;
            while (temp2 > 0) {
                numDigits++;
                temp2 /= 10;
            }

            encryptedNum = 0;
            multiplier = 1;
            for(int j = 0; j < numDigits; j++){
                encryptedNum += maxDigit * multiplier;
                multiplier *= 10;
            }
            break;
        }
        if (num == 0){
            encryptedNum = 0;
        }
        else if(maxDigit == 0 && num > 0){
            encryptedNum = num;
        }
        sum += encryptedNum;
    }
    return sum;
}