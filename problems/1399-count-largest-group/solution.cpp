class Solution {
public:
    int countLargestGroup(int n) {
        std::vector<int> group_sizes(37, 0);
        for (int i = 1; i <= n; ++i) {
            int sum = 0;
            int num = i;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            group_sizes[sum]++;
        }
        int max_size = 0;
        for (int size : group_sizes) {
            if (size > max_size) {
                max_size = size;
            }
        }
        int count = 0;
        for (int size : group_sizes) {
            if (size == max_size) {
                count++;
            }
        }
        return count;
    }
};