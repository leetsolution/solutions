class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        vector<int> dist(n, -1);
        dist[0] = 0;
        queue<int> q;
        q.push(0);

        vector<bool> visited_prime(1000001, false);
        vector<int> primes;
        vector<bool> is_prime(1000001, true);
        is_prime[0] = is_prime[1] = false;
        for (int p = 2; p <= 1000000; ++p) {
            if (is_prime[p]) {
                primes.push_back(p);
                for (int i = p + p; i <= 1000000; i += p) {
                    is_prime[i] = false;
                }
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == n - 1) return dist[u];

            if (u > 0 && dist[u - 1] == -1) {
                dist[u - 1] = dist[u] + 1;
                q.push(u - 1);
            }

            if (u < n - 1 && dist[u + 1] == -1) {
                dist[u + 1] = dist[u] + 1;
                q.push(u + 1);
            }

            if (is_prime[nums[u]] && !visited_prime[nums[u]]) {
                visited_prime[nums[u]] = true;
                for (int v = 0; v < n; ++v) {
                    if (u != v && nums[v] % nums[u] == 0 && dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        return dist[n - 1];
    }
};