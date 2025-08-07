int numberOfChild(int n, int k) {
    int period = n - 1;
    int num_periods = k / period;
    int remaining_steps = k % period;

    if (num_periods % 2 == 0) {
        return remaining_steps;
    } else {
        return n - 1 - remaining_steps;
    }
}