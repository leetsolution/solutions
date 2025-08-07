class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size();
        int max_captured = 0;
        for (int i = 0; i < n; ++i) {
            if (forts[i] == 1) {
                for (int j = 0; j < n; ++j) {
                    if (forts[j] == -1) {
                        int captured = 0;
                        bool possible = true;
                        int start = min(i, j) + 1;
                        int end = max(i, j);
                        for (int k = start; k < end; ++k) {
                            if (forts[k] != 0) {
                                possible = false;
                                break;
                            } else {
                                captured++;
                            }
                        }
                        if (possible) {
                            max_captured = max(max_captured, captured);
                        }
                    }
                }
            } else if (forts[i] == -1) {
                for (int j = 0; j < n; ++j) {
                    if (forts[j] == 1) {
                        int captured = 0;
                        bool possible = true;
                        int start = min(i, j) + 1;
                        int end = max(i, j);
                        for (int k = start; k < end; ++k) {
                            if (forts[k] != 0) {
                                possible = false;
                                break;
                            } else {
                                captured++;
                            }
                        }
                        if (possible) {
                            max_captured = max(max_captured, captured);
                        }
                    }
                }
            }
        }
        return max_captured;
    }
};