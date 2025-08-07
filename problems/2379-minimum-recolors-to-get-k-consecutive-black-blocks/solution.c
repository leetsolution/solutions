int minimumRecolors(char* blocks, int k) {
    int n = 0;
    while (blocks[n] != '\0') {
        n++;
    }

    int min_recolors = k;
    int current_recolors = 0;

    for (int i = 0; i < k; i++) {
        if (blocks[i] == 'W') {
            current_recolors++;
        }
    }

    min_recolors = current_recolors;

    for (int i = k; i < n; i++) {
        if (blocks[i] == 'W') {
            current_recolors++;
        }
        if (blocks[i - k] == 'W') {
            current_recolors--;
        }
        if (current_recolors < min_recolors) {
            min_recolors = current_recolors;
        }
    }

    return min_recolors;
}