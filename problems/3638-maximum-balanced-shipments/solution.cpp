class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
    class Solution {
    public:
        int balancedShipments(vector<int>& weight) {
            int n = weight.size();
            int count = 0;
            int i = 0;
            while (i < n) {
                int max_weight = 0;
                int j = i;
                while (j < n) {
                    max_weight = max(max_weight, weight[j]);
                    if (weight[j] < max_weight) {
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