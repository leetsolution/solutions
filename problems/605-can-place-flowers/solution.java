class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int count = 0;
        int i = 0;
        while (i < flowerbed.length) {
            if (flowerbed[i] == 0) {
                boolean canPlace = true;
                if (i > 0 && flowerbed[i - 1] == 1) {
                    canPlace = false;
                }
                if (i < flowerbed.length - 1 && flowerbed[i + 1] == 1) {
                    canPlace = false;
                }
                if (canPlace) {
                    flowerbed[i] = 1;
                    count++;
                }
            }
            if (count >= n) {
                return true;
            }
            i++;
        }
        return count >= n;
    }
}