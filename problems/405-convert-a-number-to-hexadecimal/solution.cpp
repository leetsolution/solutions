class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string hex = "0123456789abcdef";
        string result = "";
        unsigned int n = num;
        while (n > 0) {
            result = hex[n % 16] + result;
            n /= 16;
        }
        if (num < 0) {
            unsigned int nn = num;
            string res = "";
            while(nn > 0){
                res = hex[nn % 16] + res;
                nn /= 16;
            }
            int len = res.length();
            while(len < 8){
                res = "f" + res;
                len++;
            }
            return res;

        }
        return result;
    }
};