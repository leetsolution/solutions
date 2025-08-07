int finalPositionOfSnake(int n, char** commands, int commandsSize) {
    int row = 0;
    int col = 0;

    for (int i = 0; i < commandsSize; i++) {
        if (strcmp(commands[i], "UP") == 0) {
            row--;
        } else if (strcmp(commands[i], "DOWN") == 0) {
            row++;
        } else if (strcmp(commands[i], "RIGHT") == 0) {
            col++;
        } else if (strcmp(commands[i], "LEFT") == 0) {
            col--;
        }
    }

    return (row * n) + col;
}