class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> population(101, 0);
        for (auto& log : logs) {
            population[log[0] - 1950]++;
            population[log[1] - 1950]--;
        }
        int maxPop = 0;
        int year = 1950;
        int currentPop = 0;
        for (int i = 0; i < 101; i++) {
            currentPop += population[i];
            if (currentPop > maxPop) {
                maxPop = currentPop;
                year = 1950 + i;
            }
        }
        return year;
    }
};