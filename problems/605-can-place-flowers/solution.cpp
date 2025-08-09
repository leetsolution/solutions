class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int len = flowerbed.size();
        for (int i = 0; i < len; i++) {
            if (flowerbed[i] == 0) {
                bool canPlace = true;
                if (i > 0 && flowerbed[i - 1] == 1) canPlace = false;
                if (i < len - 1 && flowerbed[i + 1] == 1) canPlace = false;
                if (canPlace) {
                    flowerbed[i] = 1;
                    count++;
                }
            }
            if (count >= n) return true;
        }
        return count >= n;
    }
};