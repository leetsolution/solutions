class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum_apple = 0;
        for (int a : apple) {
            sum_apple += a;
        }
        sort(capacity.begin(), capacity.end(), greater<int>());
        int count = 0;
        int sum_capacity = 0;
        for (int c : capacity) {
            sum_capacity += c;
            count++;
            if (sum_capacity >= sum_apple) {
                return count;
            }
        }
        return capacity.size();
    }
};