class Solution {
public:
    string reformat(string s) {
        string digits = "";
        string letters = "";
        for (char c : s) {
            if (isdigit(c)) {
                digits += c;
            } else {
                letters += c;
            }
        }

        int digits_len = digits.length();
        int letters_len = letters.length();

        if (abs(digits_len - letters_len) > 1) {
            return "";
        }

        string result = "";
        if (digits_len > letters_len) {
            for (int i = 0; i < s.length(); ++i) {
                if (i % 2 == 0) {
                    result += digits[i / 2];
                } else {
                    result += letters[i / 2];
                }
            }
        } else if (letters_len > digits_len) {
            for (int i = 0; i < s.length(); ++i) {
                if (i % 2 == 0) {
                    result += letters[i / 2];
                } else {
                    result += digits[i / 2];
                }
            }
        } else {
            for (int i = 0; i < s.length(); ++i) {
                if (isdigit(s[0])) {
                  if (i % 2 == 0) {
                      result += digits[i / 2];
                  } else {
                      result += letters[i / 2];
                  }
                } else {
                  if (i % 2 == 0) {
                      result += letters[i / 2];
                  } else {
                      result += digits[i / 2];
                  }
                }
            }
           if(abs((int)result[0] - (int)digits[0]) > 9){
             string temp = "";
             for (int i = 0; i < s.length(); ++i) {
                if (isdigit(s[0])) {
                  if (i % 2 == 0) {
                      temp += letters[i / 2];
                  } else {
                      temp += digits[i / 2];
                  }
                } else {
                  if (i % 2 == 0) {
                      temp += digits[i / 2];
                  } else {
                      temp += letters[i / 2];
                  }
                }
            }
             result = temp;
           }
            
        }

        return result;
    }
};