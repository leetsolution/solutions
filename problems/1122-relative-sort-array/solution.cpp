class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        vector<int> remaining;
        vector<int> count(1001, 0);

        for (int num : arr1) {
            count[num]++;
        }

        for (int num : arr2) {
            while (count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }
        }

        for (int i = 0; i <= 1000; ++i) {
            while (count[i] > 0) {
                remaining.push_back(i);
                count[i]--;
            }
        }
        
        result.insert(result.end(), remaining.begin(), remaining.end());
        return result;
    }
};