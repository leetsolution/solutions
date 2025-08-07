class Solution {
public:
    int similarPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                string word1 = words[i];
                string word2 = words[j];

                bool similar = true;
                for (char c = 'a'; c <= 'z'; ++c) {
                    bool present1 = false;
                    bool present2 = false;

                    for (char ch : word1) {
                        if (ch == c) {
                            present1 = true;
                            break;
                        }
                    }

                    for (char ch : word2) {
                        if (ch == c) {
                            present2 = true;
                            break;
                        }
                    }

                    if (present1 != present2) {
                        similar = false;
                        break;
                    }
                }

                if (similar) {
                    count++;
                }
            }
        }
        return count;
    }
};