class Solution {
public:
    int minLength(string s) {
        string stack = "";
        for (char c : s) {
            stack += c;
            while (stack.length() >= 2) {
                int n = stack.length();
                if ((stack[n - 2] == 'A' && stack[n - 1] == 'B') || (stack[n - 2] == 'C' && stack[n - 1] == 'D')) {
                    stack.pop_back();
                    stack.pop_back();
                } else {
                    break;
                }
            }
        }
        return stack.length();
    }
};