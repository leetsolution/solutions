class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map1;
        for (int i = 0; i < list1.size(); ++i) {
            map1[list1[i]] = i;
        }
        vector<string> result;
        int minSum = INT_MAX;
        for (int i = 0; i < list2.size(); ++i) {
            if (map1.count(list2[i])) {
                int sum = map1[list2[i]] + i;
                if (sum < minSum) {
                    minSum = sum;
                    result.clear();
                    result.push_back(list2[i]);
                } else if (sum == minSum) {
                    result.push_back(list2[i]);
                }
            }
        }
        return result;
    }
};