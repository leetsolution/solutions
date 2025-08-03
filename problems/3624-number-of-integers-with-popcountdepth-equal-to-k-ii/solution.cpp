class Solution {
public:
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
    #include <vector>

    int countSetBits(long long n) {
        int count = 0;
        while (n > 0) {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }

    int getPopcountDepth(long long n) {
        int depth = 0;
        while (n != 1) {
            n = countSetBits(n);
            depth++;
        }
        return depth;
    }

    std::vector<int> solve(std::vector<long long>& nums, std::vector<std::vector<long long>>& queries) {
        std::vector<int> answer;
        for (const auto& query : queries) {
            if (query[0] == 1) {
                long long l = query[1];
                long long r = query[2];
                long long k = query[3];
                int count = 0;
                for (long long i = l; i <= r; ++i) {
                    if (getPopcountDepth(nums[i]) == k) {
                        count++;
                    }
                }
                answer.push_back(count);
            } else {
                long long idx = query[1];
                long long val = query[2];
                nums[idx] = val;
            }
        }
        return answer;
    }
};