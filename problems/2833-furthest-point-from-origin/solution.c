int furthestDistanceFromOrigin(char* moves) {
    int right = 0;
    int left = 0;
    int underscore = 0;
    int i = 0;
    while (moves[i] != '\0') {
        if (moves[i] == 'R') {
            right++;
        } else if (moves[i] == 'L') {
            left++;
        } else {
            underscore++;
        }
        i++;
    }
    if (right > left + underscore) {
        return right - left - underscore;
    } else {
        return underscore - (right - left);
    }
}