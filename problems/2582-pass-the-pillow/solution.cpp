class Solution {
public:
    int passThePillow(int n, int time) {
        if (time <= n) return time;
        time -= n;
        int cycle_len = 2 * (n - 1);
        time %= cycle_len;
        if (time <= n -1) return n - time;
        else return time - (n - 1) + 1;
    }
};