class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n = cost.size();
        vector<int> answer(n);
        if (n == 0) {
            return answer;
        }
        answer[0] = cost[0];
        for (int i = 1; i < n; ++i) {
            answer[i] = min(answer[i - 1], cost[i]);
        }
        return answer;
    }
};