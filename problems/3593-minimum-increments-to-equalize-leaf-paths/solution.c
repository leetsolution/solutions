int minIncrease(int n, int** edges, int edgesSize, int* edgesColSize, int* cost, int costSize) {
    int *adj[n];
    int degree[n];
    for (int i = 0; i < n; i++) {
        adj[i] = (int *)malloc(n * sizeof(int));
        degree[i] = 0;
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][degree[u]++] = v;
        adj[v][degree[v]++] = u;
    }

    int leaves = 0;
    for (int i = 0; i < n; i++) {
        if (i != 0 && degree[i] == 1) {
            leaves++;
        }
    }

    if (leaves == 0) return 0;

    long long max_path_sum = 0;
    long long total_increase = 0;

    int *q = (int *)malloc(n * sizeof(int));
    int q_front = 0, q_rear = 0;
    q[q_rear++] = 0;
    
    while (q_front < q_rear) {
        int current_node = q[q_front++];
        int is_leaf = 1;
        for (int i = 0; i < degree[current_node]; i++) {
            int neighbor = adj[current_node][i];
            if (neighbor != 0 && degree[neighbor] == 1 && neighbor > current_node)
            {
              long long path_sum = cost[0];
              int current = neighbor;
              int parent = current_node;

              path_sum += cost[current];
              
              while(degree[current] > 1)
              {
                int next = -1;
                for(int j = 0; j < degree[current]; j++)
                {
                    int temp_neighbor = adj[current][j];
                    if(temp_neighbor != parent)
                    {
                      next = temp_neighbor;
                      break;
                    }
                }
                if(next == -1) break;
                path_sum += cost[next];
                parent = current;
                current = next;
              }
              
              if (path_sum > max_path_sum) {
                max_path_sum = path_sum;
              }
              is_leaf = 0;
            }
        }
        
        if(is_leaf && degree[current_node] == 1 && current_node != 0){
          long long path_sum = cost[0];
          int current = current_node;
          int parent = -1;
          
          path_sum += cost[current];
          
          while(current != 0)
          {
            int next = -1;
            for(int j = 0; j < degree[current]; j++)
            {
                int temp_neighbor = adj[current][j];
                if(temp_neighbor != parent)
                {
                  next = temp_neighbor;
                  break;
                }
            }
            if(next == -1) break;
            path_sum += cost[next];
            parent = current;
            current = next;
          }
          if (path_sum > max_path_sum) {
            max_path_sum = path_sum;
          }
        }
        
        for (int i = 0; i < degree[current_node]; i++) {
            int neighbor = adj[current_node][i];
            if(neighbor != 0 && degree[neighbor] > 1 && neighbor > current_node)
            {
                q[q_rear++] = neighbor;
            }
        }
    }

    q_front = 0;
    q_rear = 0;
    q[q_rear++] = 0;
    
    while (q_front < q_rear) {
        int current_node = q[q_front++];
        int is_leaf = 1;
        for (int i = 0; i < degree[current_node]; i++) {
            int neighbor = adj[current_node][i];
            if (neighbor != 0 && degree[neighbor] == 1 && neighbor > current_node)
            {
              long long path_sum = cost[0];
              int current = neighbor;
              int parent = current_node;

              path_sum += cost[current];
              
              while(degree[current] > 1)
              {
                int next = -1;
                for(int j = 0; j < degree[current]; j++)
                {
                    int temp_neighbor = adj[current][j];
                    if(temp_neighbor != parent)
                    {
                      next = temp_neighbor;
                      break;
                    }
                }
                if(next == -1) break;
                path_sum += cost[next];
                parent = current;
                current = next;
              }

              if (path_sum < max_path_sum) {
                  total_increase += (max_path_sum - path_sum);
              }
              is_leaf = 0;
            }
        }
                if(is_leaf && degree[current_node] == 1 && current_node != 0){
          long long path_sum = cost[0];
          int current = current_node;
          int parent = -1;
          
          path_sum += cost[current];
          
          while(current != 0)
          {
            int next = -1;
            for(int j = 0; j < degree[current]; j++)
            {
                int temp_neighbor = adj[current][j];
                if(temp_neighbor != parent)
                {
                  next = temp_neighbor;
                  break;
                }
            }
            if(next == -1) break;
            path_sum += cost[next];
            parent = current;
            current = next;
          }
          
              if (path_sum < max_path_sum) {
                  total_increase += (max_path_sum - path_sum);
              }
        }
        
        for (int i = 0; i < degree[current_node]; i++) {
            int neighbor = adj[current_node][i];
            if(neighbor != 0 && degree[neighbor] > 1 && neighbor > current_node)
            {
                q[q_rear++] = neighbor;
            }
        }
    }
    free(q);

    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }

    return total_increase > 0;
}