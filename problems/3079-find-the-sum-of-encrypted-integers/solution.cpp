class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            int temp = num;
            int maxDigit = 0;
            while (temp > 0) {
                int digit = temp % 10;
                maxDigit = max(maxDigit, digit);
                temp /= 10;
            }

            int encryptedNum = 0;
            int multiplier = 1;
            temp = num;
            while (temp > 0) {
                int numDigits = 0;
                int temp2 = num;
                while (temp2 > 0)
                {
                    numDigits++;
                    temp2 /= 10;
                }
                encryptedNum = 0;
                multiplier = 1;
                for(int i = 0; i < numDigits; i++){
                    encryptedNum += maxDigit * multiplier;
                    multiplier *= 10;
                }
                break;
            }
            if (num == 0) {
                encryptedNum = 0;
            }

            sum += encryptedNum;
        }
        return sum;
    }
};