char* destCity(char*** paths, int pathsSize, int* pathsColSize) {
    int i, j;
    int isDestination;

    for (i = 0; i < pathsSize; i++) {
        isDestination = 1;
        char* destination = paths[i][1];

        for (j = 0; j < pathsSize; j++) {
            if (i != j && strcmp(destination, paths[j][0]) == 0) {
                isDestination = 0;
                break;
            }
        }

        if (isDestination) {
            return destination;
        }
    }

    return NULL;
}