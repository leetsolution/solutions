class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;
        vector<int> counts(10, 0);
        for (int digit : digits) {
            counts[digit]++;
        }

        for (int i = 100; i <= 999; ++i) {
            int a = i / 100;
            int b = (i % 100) / 10;
            int c = i % 10;

            if (c % 2 != 0) continue;

            vector<int> temp_counts = counts;
            temp_counts[a]--;
            if (temp_counts[a] < 0) continue;
            temp_counts[b]--;
            if (temp_counts[b] < 0) continue;
            temp_counts[c]--;
            if (temp_counts[c] < 0) continue;

            result.push_back(i);
        }

        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};