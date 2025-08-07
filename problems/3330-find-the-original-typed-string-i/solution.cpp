class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int count = 1;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && word[i] == word[j]) {
                j++;
            }
            if (j - i > 1) {
                count += (j - i - 1);
                i = j;
            } else {
                i++;
            }
        }
        return count;
    }
};