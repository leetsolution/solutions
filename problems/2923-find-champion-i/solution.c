int findChampion(int** grid, int gridSize, int* gridColSize) {
    for (int i = 0; i < gridSize; i++) {
        int champion = 1;
        for (int j = 0; j < gridSize; j++) {
            if (i != j && grid[j][i] == 1) {
                champion = 0;
                break;
            }
        }
        if (champion) {
            return i;
        }
    }
    return -1;
}