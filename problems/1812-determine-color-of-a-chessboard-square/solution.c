bool squareIsWhite(char* coordinates) {
    int column = coordinates[0] - 'a' + 1;
    int row = coordinates[1] - '0';

    if ((column + row) % 2 == 0) {
        return false;
    } else {
        return true;
    }
}