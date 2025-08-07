int maxDivScore(int* nums, int numsSize, int* divisors, int divisorsSize) {
    int maxScore = -1;
    int bestDivisor = -1;
    for (int i = 0; i < divisorsSize; i++) {
        int score = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] % divisors[i] == 0) {
                score++;
            }
        }
        if (score > maxScore) {
            maxScore = score;
            bestDivisor = divisors[i];
        } else if (score == maxScore && score != -1) {
            bestDivisor = (bestDivisor < divisors[i]) ? bestDivisor : divisors[i];
        }
    }
    return bestDivisor;
}