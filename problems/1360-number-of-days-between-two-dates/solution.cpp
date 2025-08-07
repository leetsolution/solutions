class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        int y1 = stoi(date1.substr(0, 4));
        int m1 = stoi(date1.substr(5, 2));
        int d1 = stoi(date1.substr(8, 2));
        int y2 = stoi(date2.substr(0, 4));
        int m2 = stoi(date2.substr(5, 2));
        int d2 = stoi(date2.substr(8, 2));

        auto days_from_epoch = [](int y, int m, int d) {
            static const int days_before_month[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
            y -= (m <= 2);
            int era = y / 400;
            y -= era * 400;
            int ans = 365 * y + y / 4 - y / 100;
            ans += days_before_month[m - 1] + d;
            ans += era * 146097;
            return ans;
        };

        return abs(days_from_epoch(y1, m1, d1) - days_from_epoch(y2, m2, d2));
    }
};