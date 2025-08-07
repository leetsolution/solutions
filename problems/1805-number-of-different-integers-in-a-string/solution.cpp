class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> s;
        string num = "";
        for (char c : word) {
            if (isdigit(c)) {
                num += c;
            } else {
                if (!num.empty()) {
                    int i = 0;
                    while (i < num.length() - 1 && num[i] == '0') {
                        i++;
                    }
                    s.insert(num.substr(i));
                    num = "";
                }
            }
        }
        if (!num.empty()) {
            int i = 0;
            while (i < num.length() - 1 && num[i] == '0') {
                i++;
            }
            s.insert(num.substr(i));
        }
        return s.size();
    }
};