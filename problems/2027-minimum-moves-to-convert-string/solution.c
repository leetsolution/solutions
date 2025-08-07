int minimumMoves(char* s) {
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }
    int moves = 0;
    for (int i = 0; i < n;) {
        if (s[i] == 'X') {
            moves++;
            i += 3;
        } else {
            i++;
        }
    }
    return moves;
}