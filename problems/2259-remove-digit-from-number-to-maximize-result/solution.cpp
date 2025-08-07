class Solution {
public:
    string removeDigit(string number, char digit) {
        string res = "";
        for (int i = 0; i < number.length(); ++i) {
            if (number[i] == digit) {
                string temp = number.substr(0, i) + number.substr(i + 1);
                if (res == "" || stoll(temp) > stoll(res)) {
                    res = temp;
                }
            }
        }
        return res;
    }
};