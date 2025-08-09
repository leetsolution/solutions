class Solution {
public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int max_path_sum = 0;
        int increases = 0;
        vector<bool> visited(n, false);

        function<void(int, int)> dfs = [&](int node, int current_sum) {
            visited[node] = true;
            current_sum += cost[node];

            bool is_leaf = true;
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    is_leaf = false;
                    dfs(neighbor, current_sum);
                }
            }

            if (is_leaf) {
                max_path_sum = max(max_path_sum, current_sum);
            }
            visited[node] = false;
        };

        function<void(int, int)> dfs2 = [&](int node, int current_sum) {
            visited[node] = true;
            current_sum += cost[node];

            bool is_leaf = true;
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    is_leaf = false;
                    dfs2(neighbor, current_sum);
                }
            }

            if (is_leaf) return;

            int max_child_path = 0;
            bool has_unvisited_children = false;
            for(int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    has_unvisited_children = true;
                    vector<bool> temp_visited(n, false);
                    function<int(int, int)> get_max_child_path = [&](int child_node, int child_sum) -> int{
                        temp_visited[child_node] = true;
                        child_sum += cost[child_node];

                        bool child_is_leaf = true;
                        int temp_max = 0;
                        for(int child_neighbor : adj[child_node]){
                            if(!temp_visited[child_neighbor]){
                                child_is_leaf = false;
                                temp_max = max(temp_max, get_max_child_path(child_neighbor, child_sum));
                            }
                        }
                        if(child_is_leaf){
                            return child_sum;
                        }
                        temp_visited[child_node] = false;
                        return temp_max;
                    };
                    
                    
                    max_child_path = max(max_child_path, get_max_child_path(neighbor, 0));
                }
            }
            
            if(has_unvisited_children){
                int target_sum = max_path_sum - cost[node];
                
                int diff = target_sum - max_child_path;

                if(diff > 0){
                    increases++;
                }
            }
            visited[node] = false;
        };

        dfs(0, 0);
        fill(visited.begin(), visited.end(), false);
        dfs2(0, 0);

        return increases;
    }
};