#include <algorithm>
#include <vector>

class Solution {
public:
    int fillCups(std::vector<int>& amount) {
        std::sort(amount.begin(), amount.end());
        int a = amount[0];
        int b = amount[1];
        int c = amount[2];
        if (a + b <= c) {
            return c;
        }
        return (a + b + c + 1) / 2;
    }
};