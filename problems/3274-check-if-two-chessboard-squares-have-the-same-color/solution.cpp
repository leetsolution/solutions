class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int c1 = coordinate1[0] - 'a';
        int r1 = coordinate1[1] - '1';
        int c2 = coordinate2[0] - 'a';
        int r2 = coordinate2[1] - '1';
        return (c1 + r1) % 2 == (c2 + r2) % 2;
    }
};