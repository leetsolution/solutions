class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        if (k <= 1) return 0;

        int low = 0, high = 1e9;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            vector<int> parent(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }

            function<int(int)> find = [&](int x) {
                if (parent[x] == x) return x;
                return parent[x] = find(parent[x]);
            };

            auto unite = [&](int x, int y) {
                x = find(x);
                y = find(y);
                if (x != y) {
                    parent[x] = y;
                }
            };

            for (auto& edge : edges) {
                if (edge[2] > mid) {
                    unite(edge[0], edge[1]);
                }
            }

            int components = 0;
            vector<bool> visited(n, false);
            for (int i = 0; i < n; i++) {
                if (!visited[find(i)]) {
                    components++;
                    visited[find(i)] = true;
                }
            }

            if (components >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (ans == 0 && edges.size() == 0 && k <= 1) return 0;

        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        function<int(int)> find = [&](int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        };

        auto unite = [&](int x, int y) {
            x = find(x);
            y = find(y);
            if (x != y) {
                parent[x] = y;
            }
        };

        int components = 0;
        for (auto& edge : edges) {
              unite(edge[0], edge[1]);
           
        }
          vector<bool> visited(n, false);
            for (int i = 0; i < n; i++) {
                if (!visited[find(i)]) {
                    components++;
                    visited[find(i)] = true;
                }
            }
        
        if(components >= k) return 0;

        return ans;
    }
};