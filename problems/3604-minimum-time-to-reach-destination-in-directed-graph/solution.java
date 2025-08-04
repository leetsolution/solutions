import java.util.*;
class Solution {
    public int minTime(int n, int[][] edges) {
        // Build adjacency list with edge time windows
        List<int[]>[] graph = new List[n];
        for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
        for (int[] e : edges) {
            int u = e[0], v = e[1], start = e[2], end = e[3];
            graph[u].add(new int[]{v, start, end});
        }

        // BFS: queue holds {node, time}
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{0, 0});
        int[] visited = new int[n];
        Arrays.fill(visited, Integer.MAX_VALUE);
        visited[0] = 0;

        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int node = curr[0], time = curr[1];
            if (node == n - 1) return time;
            // Wait at current node
            if (time + 1 < visited[node]) {
                visited[node] = time + 1;
                q.offer(new int[]{node, time + 1});
            }
            // Try all outgoing edges
            for (int[] e : graph[node]) {
                int v = e[0], start = e[1], end = e[2];
                if (time >= start && time <= end && time < visited[v]) {
                    visited[v] = time;
                    q.offer(new int[]{v, time});
                }
            }
        }
        return -1;
    }
}