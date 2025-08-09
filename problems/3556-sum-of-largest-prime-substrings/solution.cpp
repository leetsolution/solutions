class Solution {
public:
    long long sumOfLargestPrimes(string s) {
        long long result = 0;
        std::set<int> primes;
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i; j < s.length(); ++j) {
                std::string sub = s.substr(i, j - i + 1);
                if (sub[0] == '0' && sub.length() > 1) continue;
                int num = std::stoi(sub);
                if (num <= 1) continue;
                bool isPrime = true;
                for (int k = 2; k * k <= num; ++k) {
                    if (num % k == 0) {
                        isPrime = false;
                        break;
                    }
                }
                if (isPrime) {
                    primes.insert(num);
                }
            }
        }
        
        std::vector<int> sortedPrimes(primes.begin(), primes.end());
        std::sort(sortedPrimes.begin(), sortedPrimes.end(), std::greater<int>());
        
        int count = std::min((int)sortedPrimes.size(), 3);
        for (int i = 0; i < count; ++i) {
            result += sortedPrimes[i];
        }
        
        return result;
    }
};