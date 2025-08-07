class Solution {
    public boolean squareIsWhite(String coordinates) {
        char file = coordinates.charAt(0);
        char rank = coordinates.charAt(1);

        if ((file - 'a') % 2 == 0) {
            return (rank - '1') % 2 != 0;
        } else {
            return (rank - '1') % 2 == 0;
        }
    }
}