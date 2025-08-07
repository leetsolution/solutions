class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        vector<int> odd, even;
        for (char c : s) {
            if ((c - '0') % 2 == 0) {
                even.push_back(c - '0');
            } else {
                odd.push_back(c - '0');
            }
        }
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end(), greater<int>());
        int oi = 0, ei = 0;
        string res = "";
        for (char c : s) {
            if ((c - '0') % 2 == 0) {
                res += to_string(even[ei++]);
            } else {
                res += to_string(odd[oi++]);
            }
        }
        return stoi(res);
    }
};