class Solution {
    public String concatHex36(int n) {
        int n2 = n * n;
        int n3 = n * n * n;
        String hex = Integer.toHexString(n2).toUpperCase();
        String base36 = Integer.toString(n3, 36).toUpperCase();
        return hex + base36;
    }
}