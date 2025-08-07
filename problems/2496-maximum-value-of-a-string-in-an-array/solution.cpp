class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int maxVal = 0;
        for (const string& s : strs) {
            bool isNumeric = true;
            for (char c : s) {
                if (!isdigit(c)) {
                    isNumeric = false;
                    break;
                }
            }

            int val;
            if (isNumeric) {
                val = stoi(s);
            } else {
                val = s.length();
            }

            maxVal = max(maxVal, val);
        }
        return maxVal;
    }
};