class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        return std::min((long long)n * n, (long long)maxWeight / w);
    }
};