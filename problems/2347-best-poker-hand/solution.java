class Solution {
    public String bestHand(int[] ranks, char[] suits) {
        boolean flush = true;
        for (int i = 1; i < 5; i++) {
            if (suits[i] != suits[0]) {
                flush = false;
                break;
            }
        }
        if (flush) {
            return "Flush";
        }

        int[] rankCounts = new int[14];
        for (int rank : ranks) {
            rankCounts[rank]++;
        }

        boolean threeOfAKind = false;
        boolean pair = false;
        for (int count : rankCounts) {
            if (count >= 3) {
                threeOfAKind = true;
                break;
            } else if (count == 2) {
                pair = true;
            }
        }

        if (threeOfAKind) {
            return "Three of a Kind";
        } else if (pair) {
            return "Pair";
        } else {
            return "High Card";
        }
    }
}