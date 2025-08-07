int numberOfAlternatingGroups(int* colors, int colorsSize) {
    int count = 0;
    for (int i = 0; i < colorsSize; i++) {
        int prev = (i - 1 + colorsSize) % colorsSize;
        int next = (i + 1) % colorsSize;
        if (colors[i] != colors[prev] && colors[i] != colors[next]) {
            count++;
        }
    }
    return count;
}