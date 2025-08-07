class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string result = "";
        for (int i = 0; i < indices.size(); ++i) {
            result += s[i];
        }
        string shuffled = "";
        for (int i = 0; i < indices.size(); ++i) {
            shuffled += result[indices[i]];
        }
        return shuffled;
    }
};