class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int n = tickets.length;
        int time = 0;
        for (int i = 0; i < n; i++) {
            if (tickets[i] <= tickets[k]) {
                if (i <= k) {
                    time += tickets[i];
                } else {
                    time += tickets[i];
                }
            } else {
                if (i <= k) {
                    time += tickets[k];
                } else {
                    time += tickets[k];
                }
            }
        }
        return time;
    }
}