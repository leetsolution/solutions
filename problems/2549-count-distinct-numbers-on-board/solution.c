int distinctIntegers(int n) {
    int board[101] = {0};
    board[n] = 1;
    int count = 1;
    int changed = 1;
    while (changed) {
        changed = 0;
        int new_board[101] = {0};
        for (int i = 1; i <= n; i++) {
            if (board[i]) {
                for (int j = 1; j <= n; j++) {
                    if (i % j == 1) {
                        if (!board[j]) {
                            changed = 1;
                        }
                        new_board[j] = 1;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            board[i] = board[i] | new_board[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (board[i]) {
            count++;
        }
    }
    return count;
}