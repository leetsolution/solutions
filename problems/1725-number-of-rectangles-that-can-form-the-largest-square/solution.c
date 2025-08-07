int countGoodRectangles(int** rectangles, int rectanglesSize, int* rectanglesColSize){
    int maxLen = 0;
    int count = 0;

    for (int i = 0; i < rectanglesSize; i++) {
        int len = rectangles[i][0];
        int width = rectangles[i][1];
        int side = (len < width) ? len : width;

        if (side > maxLen) {
            maxLen = side;
            count = 1;
        } else if (side == maxLen) {
            count++;
        }
    }

    return count;
}