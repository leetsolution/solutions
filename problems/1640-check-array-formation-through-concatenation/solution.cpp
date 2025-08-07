class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = arr.size();
        int i = 0;
        while (i < n) {
            bool found = false;
            for (auto& piece : pieces) {
                if (piece[0] == arr[i]) {
                    found = true;
                    for (int j = 0; j < piece.size(); ++j) {
                        if (i + j >= n || arr[i + j] != piece[j]) {
                            return false;
                        }
                    }
                    i += piece.size();
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }
};