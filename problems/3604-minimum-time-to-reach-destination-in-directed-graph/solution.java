import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

class Solution {
    public int minTime(int n, int[][] edges) {
        List<List<int[]>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adj.get(edge[0]).add(new int[]{edge[1], edge[2], edge[3]});
        }

        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[0] = 0;

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{0, 0});

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int time = curr[0];
            int u = curr[1];

            if (time > dist[u]) {
                continue;
            }

            for (int[] edge : adj.get(u)) {
                int v = edge[0];
                int start = edge[1];
                int end = edge[2];

                int nextTime = Math.max(time, start) + 1;
                if (nextTime <= end && dist[v] > nextTime) {
                    dist[v] = nextTime;
                    pq.offer(new int[]{nextTime, v});
                }
            }
        }

        return dist[n - 1] == Integer.MAX_VALUE ? -1 : dist[n - 1];
    }
}