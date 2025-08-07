#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<bool> generatePrimes(int maxVal) {
        int N = 5 * maxVal + 1;
        vector<bool> isPrime(N, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i < N; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < N; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    void insertPrimeDQ(deque<int>& minDQ, deque<int>& maxDQ, const vector<int>& nums, int idx) {
        while (!minDQ.empty() && nums[minDQ.back()] > nums[idx])
            minDQ.pop_back();
        minDQ.push_back(idx);

        while (!maxDQ.empty() && nums[maxDQ.back()] < nums[idx])
            maxDQ.pop_back();
        maxDQ.push_back(idx);
    }

    int primeSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<bool> isPrime = generatePrimes(maxNum);

        deque<int> minDQ, maxDQ, primeDQ;
        int left = 0;
        int prevPrime = 0;
        int result = 0;

        for (int i = 0; i < n; ++i) {
            int val = nums[i];

            if (val < isPrime.size() && isPrime[val]) {
                insertPrimeDQ(minDQ, maxDQ, nums, i);
                if (!primeDQ.empty()) prevPrime = primeDQ.back();
                primeDQ.push_back(i);

                while (!minDQ.empty() && !maxDQ.empty() &&
                       nums[maxDQ.front()] - nums[minDQ.front()] > k) {
                    int removeIdx = primeDQ.front();
                    primeDQ.pop_front();
                    left = removeIdx + 1;

                    if (!minDQ.empty() && minDQ.front() <= removeIdx) minDQ.pop_front();
                    if (!maxDQ.empty() && maxDQ.front() <= removeIdx) maxDQ.pop_front();
                }
            }

            if (primeDQ.size() >= 2) {
                result += prevPrime - left + 1;
            }
        }

        return result;
    }
};
