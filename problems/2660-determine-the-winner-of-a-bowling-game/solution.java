class Solution {
    public int isWinner(int[] player1, int[] player2) {
        int score1 = 0;
        int score2 = 0;
        for (int i = 0; i < player1.length; i++) {
            int val1 = player1[i];
            int val2 = player2[i];
            if (i > 1) {
                if (player1[i - 1] == 10 || player1[i - 2] == 10) {
                    val1 *= 2;
                }
                if (player2[i - 1] == 10 || player2[i - 2] == 10) {
                    val2 *= 2;
                }
            }
            score1 += val1;
            score2 += val2;
        }
        if (score1 > score2) {
            return 1;
        } else if (score2 > score1) {
            return 2;
        } else {
            return 0;
        }
    }
}