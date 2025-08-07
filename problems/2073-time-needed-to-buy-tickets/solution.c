int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int time = 0;
    for (int i = 0; i < ticketsSize; i++) {
        if (tickets[i] <= tickets[k]) {
            time += tickets[i];
        } else {
            if (i < k) {
                time += tickets[k];
            } else {
                time += tickets[k] - 1;
            }
        }
    }
    return time;
}