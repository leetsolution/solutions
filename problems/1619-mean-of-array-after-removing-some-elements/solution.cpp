class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        int trim = n / 20;
        sort(arr.begin(), arr.end());
        double sum = 0;
        for (int i = trim; i < n - trim; ++i) {
            sum += arr[i];
        }
        return sum / (n - 2 * trim);
    }
};