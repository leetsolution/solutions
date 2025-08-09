class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, pair<int, int>>>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], start = edge[2], end = edge[3];
            adj[u].push_back({v, {start, end}});
        }

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int start = edge.second.first;
                int end = edge.second.second;

                int wait_time = max(0, start - d);
                int new_dist = d + wait_time + 1;

                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    pq.push({new_dist, v});
                }
            }
        }

        return (dist[n - 1] == INT_MAX) ? -1 : dist[n - 1];
    }
};