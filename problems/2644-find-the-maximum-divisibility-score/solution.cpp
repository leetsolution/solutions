class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int maxScore = -1;
        int result = -1;
        for (int divisor : divisors) {
            int score = 0;
            for (int num : nums) {
                if (num % divisor == 0) {
                    score++;
                }
            }
            if (score > maxScore) {
                maxScore = score;
                result = divisor;
            } else if (score == maxScore && score != -1) {
                result = min(result, divisor);
            }
        }
        return result;
    }
};