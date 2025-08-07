class Solution {
public:
    int maxProduct(int n) {
        int maxDigit1 = 0;
        int maxDigit2 = 0;
        int temp = n;

        while (temp > 0) {
            int digit = temp % 10;
            if (digit > maxDigit1) {
                maxDigit2 = maxDigit1;
                maxDigit1 = digit;
            } else if (digit > maxDigit2) {
                maxDigit2 = digit;
            }
            temp /= 10;
        }

        if (maxDigit2 == 0) {
          temp = n;
            maxDigit1 = 0;
        while(temp > 0){
             int digit = temp % 10;
            if (digit > maxDigit1) {
                maxDigit1 = digit;
             }
              temp /= 10;
         }
         return maxDigit1*maxDigit1;
        }
        

        return maxDigit1 * maxDigit2;
    }
};