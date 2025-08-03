class Solution {
public:
    int minJumps(vector<int>& nums) {
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <map>

    using namespace std;

    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<int> dist(n, -1);
        dist[0] = 0;

        while (!q.empty()) {
            int u = q.front().first;
            int d = q.front().second;
            q.pop();

            if (u == n - 1) return d;

            // Adjacent step
            if (u + 1 < n && dist[u + 1] == -1) {
                dist[u + 1] = d + 1;
                q.push({u + 1, d + 1});
            }
            if (u - 1 >= 0 && dist[u - 1] == -1) {
                dist[u - 1] = d + 1;
                q.push({u - 1, d + 1});
            }

            // Prime teleportation
            if (isPrime(nums[u])) {
                for (int v = 0; v < n; ++v) {
                    if (u != v && nums[v] % nums[u] == 0 && dist[v] == -1) {
                        dist[v] = d + 1;
                        q.push({v, d + 1});
                    }
                }
            }
        }
        return -1; // Should not reach here
    }
};