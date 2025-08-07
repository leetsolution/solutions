int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
    int count = 0;
    int freq[100] = {0};
    for (int i = 0; i < dominoesSize; i++) {
        int a = dominoes[i][0];
        int b = dominoes[i][1];
        int val = (a <= b) ? a * 10 + b : b * 10 + a;
        count += freq[val];
        freq[val]++;
    }
    return count;
}