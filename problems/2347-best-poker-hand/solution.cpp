class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        bool flush = true;
        for (int i = 1; i < 5; ++i) {
            if (suits[i] != suits[0]) {
                flush = false;
                break;
            }
        }
        if (flush) return "Flush";

        vector<int> counts(14, 0);
        for (int rank : ranks) {
            counts[rank]++;
        }

        bool three = false;
        bool pair = false;
        for (int count : counts) {
            if (count >= 3) {
                three = true;
                break;
            } else if (count == 2) {
                pair = true;
            }
        }

        if (three) return "Three of a Kind";
        if (pair) return "Pair";
        return "High Card";
    }
};