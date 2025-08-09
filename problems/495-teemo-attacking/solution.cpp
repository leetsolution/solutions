class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total_poisoned_time = 0;
        if (timeSeries.empty()) {
            return 0;
        }
        total_poisoned_time += duration;
        for (size_t i = 1; i < timeSeries.size(); ++i) {
            if (timeSeries[i] - timeSeries[i - 1] < duration) {
                total_poisoned_time += timeSeries[i] - timeSeries[i - 1];
            } else {
                total_poisoned_time += duration;
            }
        }
        return total_poisoned_time;
    }
};