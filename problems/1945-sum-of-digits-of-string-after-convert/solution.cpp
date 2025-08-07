class Solution {
public:
    int getLucky(string s, int k) {
        string converted = "";
        for (char c : s) {
            converted += to_string(c - 'a' + 1);
        }

        long long num = 0;
        for (char c : converted) {
            num += c - '0';
        }

        for (int i = 1; i < k; ++i) {
            long long next_num = 0;
            string num_str = to_string(num);
            for (char c : num_str) {
                next_num += c - '0';
            }
            num = next_num;
        }

        return (int)num;
    }
};