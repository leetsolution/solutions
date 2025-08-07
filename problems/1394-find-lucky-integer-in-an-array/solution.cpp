class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> counts(501, 0);
        for (int num : arr) {
            counts[num]++;
        }
        int lucky = -1;
        for (int i = 1; i <= 500; i++) {
            if (counts[i] == i) {
                lucky = i;
            }
        }
        return lucky;
    }
};