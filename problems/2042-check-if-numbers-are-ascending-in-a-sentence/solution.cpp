class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = -1;
        string num = "";
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                num += s[i];
            } else if (num != "") {
                int curr = stoi(num);
                if (curr <= prev) {
                    return false;
                }
                prev = curr;
                num = "";
            } else {
                continue;
            }
        }
        if (num != "") {
            int curr = stoi(num);
            if (curr <= prev) {
                return false;
            }
        }
        return true;
    }
};