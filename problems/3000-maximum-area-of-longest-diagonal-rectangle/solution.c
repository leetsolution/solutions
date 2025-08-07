int areaOfMaxDiagonal(int** dimensions, int dimensionsSize, int* dimensionsColSize) {
    int maxArea = 0;
    double maxDiagonal = 0;

    for (int i = 0; i < dimensionsSize; i++) {
        int length = dimensions[i][0];
        int width = dimensions[i][1];
        double diagonal = (double)length * length + (double)width * width;

        if (diagonal > maxDiagonal) {
            maxDiagonal = diagonal;
            maxArea = length * width;
        } else if (diagonal == maxDiagonal) {
            int currentArea = length * width;
            if (currentArea > maxArea) {
                maxArea = currentArea;
            }
        }
    }

    return maxArea;
}