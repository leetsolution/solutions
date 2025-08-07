class Solution {
public:
    double average(vector<int>& salary) {
        int minVal = salary[0];
        int maxVal = salary[0];
        double sum = 0;
        for (int i = 0; i < salary.size(); i++) {
            sum += salary[i];
            minVal = min(minVal, salary[i]);
            maxVal = max(maxVal, salary[i]);
        }
        return (sum - minVal - maxVal) / (salary.size() - 2);
    }
};