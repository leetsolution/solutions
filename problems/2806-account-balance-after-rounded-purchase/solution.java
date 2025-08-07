class Solution {
    public int accountBalanceAfterPurchase(int purchaseAmount) {
        int roundedAmount = (int) Math.round(purchaseAmount / 10.0) * 10;
        return 100 - roundedAmount;
    }
}