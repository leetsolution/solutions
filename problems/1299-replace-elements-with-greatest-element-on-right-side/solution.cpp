class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};
        if (n == 1) return {-1};

        int max_right = arr[n - 1];
        arr[n - 1] = -1;

        for (int i = n - 2; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = max_right;
            max_right = max(max_right, temp);
        }

        return arr;
    }
};