class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq;
        for (long long gift : gifts) {
            pq.push(gift);
        }
        for (int i = 0; i < k; ++i) {
            long long top = pq.top();
            pq.pop();
            long long next = floor(sqrt(top));
            pq.push(next);
        }
        long long sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};