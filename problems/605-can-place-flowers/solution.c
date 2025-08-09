bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count = 0;
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 0) {
            bool canPlace = true;
            if (i > 0 && flowerbed[i - 1] == 1) canPlace = false;
            if (i < flowerbedSize - 1 && flowerbed[i + 1] == 1) canPlace = false;
            if (canPlace) {
                count++;
                flowerbed[i] = 1;
            }
        }
    }
    return count >= n;
}