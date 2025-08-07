class Solution {
public:
    int minTimeToType(string word) {
        int current = 'a';
        int seconds = 0;
        for (char c : word) {
            int diff = abs(c - current);
            seconds += min(diff, 26 - diff) + 1;
            current = c;
        }
        return seconds;
    }
};