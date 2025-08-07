#include <stdlib.h>

typedef struct {
    int** grid;
    int gridSize;
} NeighborSum;

NeighborSum* neighborSumCreate(int** grid, int gridSize, int* gridColSize) {
    NeighborSum* obj = (NeighborSum*)malloc(sizeof(NeighborSum));
    obj->gridSize = gridSize;
    obj->grid = (int**)malloc(gridSize * sizeof(int*));
    for (int i = 0; i < gridSize; i++) {
        obj->grid[i] = (int*)malloc(gridSize * sizeof(int));
        for (int j = 0; j < gridSize; j++) {
            obj->grid[i][j] = grid[i][j];
        }
    }
    return obj;
}

int neighborSumAdjacentSum(NeighborSum* obj, int value) {
    int sum = 0;
    int row = -1, col = -1;
    for (int i = 0; i < obj->gridSize; i++) {
        for (int j = 0; j < obj->gridSize; j++) {
            if (obj->grid[i][j] == value) {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1) break;
    }

    if (row > 0) sum += obj->grid[row - 1][col];
    if (row < obj->gridSize - 1) sum += obj->grid[row + 1][col];
    if (col > 0) sum += obj->grid[row][col - 1];
    if (col < obj->gridSize - 1) sum += obj->grid[row][col + 1];

    return sum;
}

int neighborSumDiagonalSum(NeighborSum* obj, int value) {
    int sum = 0;
    int row = -1, col = -1;
    for (int i = 0; i < obj->gridSize; i++) {
        for (int j = 0; j < obj->gridSize; j++) {
            if (obj->grid[i][j] == value) {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1) break;
    }

    if (row > 0 && col > 0) sum += obj->grid[row - 1][col - 1];
    if (row > 0 && col < obj->gridSize - 1) sum += obj->grid[row - 1][col + 1];
    if (row < obj->gridSize - 1 && col > 0) sum += obj->grid[row + 1][col - 1];
    if (row < obj->gridSize - 1 && col < obj->gridSize - 1) sum += obj->grid[row + 1][col + 1];

    return sum;
}

void neighborSumFree(NeighborSum* obj) {
    for (int i = 0; i < obj->gridSize; i++) {
        free(obj->grid[i]);
    }
    free(obj->grid);
    free(obj);
}