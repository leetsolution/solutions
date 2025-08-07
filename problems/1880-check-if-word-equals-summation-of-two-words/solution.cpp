class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        long long num1 = 0, num2 = 0, num3 = 0;
        for (char c : firstWord) {
            num1 = num1 * 10 + (c - 'a');
        }
        for (char c : secondWord) {
            num2 = num2 * 10 + (c - 'a');
        }
        for (char c : targetWord) {
            num3 = num3 * 10 + (c - 'a');
        }
        return num1 + num2 == num3;
    }
};