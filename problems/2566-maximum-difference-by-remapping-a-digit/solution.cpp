class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        long long max_num = 0, min_num = 0;
        int n = s.length();
        for (int i = 0; i < 10; ++i) {
            long long cur_max = 0, cur_min = 0;
            string cur_s = s;
            for (int j = 0; j < n; ++j) {
                if (s[j] - '0' == i) {
                    cur_s[j] = '9';
                }
            }
            cur_max = stoll(cur_s);

            cur_s = s;
            for (int j = 0; j < n; ++j) {
                if (s[j] - '0' == i) {
                    cur_s[j] = '0';
                }
            }
            cur_min = stoll(cur_s);
            
            if (i == 0) {
                max_num = cur_max;
                min_num = cur_min;
            } else {
                max_num = max(max_num, cur_max);
                min_num = min(min_num, cur_min);
            }
        }
        return max_num - min_num;
    }
};