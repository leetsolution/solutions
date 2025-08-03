class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
    class Solution {
    public:
        int balancedShipments(vector<long long>& weight) {
            int n = weight.size();
            int count = 0;
            int i = 0;
            while (i < n) {
                int j = i;
                long long maxWeight = 0;
                while (j < n) {
                    maxWeight = max(maxWeight, weight[j]);
                    if (weight[j] < maxWeight) {
                        count++;
                        i = j + 1;
                        break;
                    }
                    j++;
                }
                if (j == n) break;

            }
            return count;
        }
    };
};