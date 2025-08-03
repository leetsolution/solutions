class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
    #include <iostream>
    #include <vector>
    #include <climits>

    using namespace std;

    long long solve() {
        int n;
        cin >> n;
        vector<long long> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        long long max_sum = LLONG_MIN;
        for (int l = 0; l < n - 3; ++l) {
            for (int p = l + 1; p < n - 2; ++p) {
                for (int q = p + 1; q < n - 1; ++q) {
                    for (int r = q + 1; r < n; ++r) {
                        bool inc1 = true, dec2 = true, inc3 = true;
                        for (int i = l + 1; i <= p; ++i) {
                            if (nums[i] <= nums[i - 1]) {
                                inc1 = false;
                                break;
                            }
                        }
                        for (int i = p + 1; i <= q; ++i) {
                            if (nums[i] >= nums[i - 1]) {
                                dec2 = false;
                                break;
                            }
                        }
                        for (int i = q + 1; i <= r; ++i) {
                            if (nums[i] <= nums[i - 1]) {
                                inc3 = false;
                                break;
                            }
                        }

                        if (inc1 && dec2 && inc3) {
                            long long current_sum = 0;
                            for (int i = l; i <= r; ++i) {
                                current_sum += nums[i];
                            }
                            max_sum = max(max_sum, current_sum);
                        }
                    }
                }
            }
        }
        return max_sum;
    }

    int main() {
        cout << solve() << endl;
        return 0;
    }
};