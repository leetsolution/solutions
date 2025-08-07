class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.length() < 2) {
            return "";
        }

        string result = "";
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i + 1; j <= s.length(); ++j) {
                string sub = s.substr(i, j - i);
                bool nice = true;
                for (char c : sub) {
                    if (islower(c)) {
                        if (sub.find(toupper(c)) == string::npos) {
                            nice = false;
                            break;
                        }
                    } else {
                        if (sub.find(tolower(c)) == string::npos) {
                            nice = false;
                            break;
                        }
                    }
                }

                if (nice) {
                    if (sub.length() > result.length()) {
                        result = sub;
                    }
                }
            }
        }

        return result;
    }
};