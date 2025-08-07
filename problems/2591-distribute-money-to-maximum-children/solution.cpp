class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) return -1;
        money -= children;
        int count8 = min(money / 8, children);
        money -= count8 * 8;
        if (money == 0) return count8;
        if (money < children - count8) return -1;
        return count8 - (money > 0);

    }
};