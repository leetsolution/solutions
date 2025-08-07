class Solution {
    public int passThePillow(int n, int time) {
        if (time <= n) {
            return time;
        }
        time -= n;
        int cycle = (n - 1) * 2;
        int rem = time % cycle;
        if (rem == 0) {
            return n;
        }
        if (rem <= n - 1) {
            return n - rem;
        } else {
            return rem - (n - 1);
        }
    }
}