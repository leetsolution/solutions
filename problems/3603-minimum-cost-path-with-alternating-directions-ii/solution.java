import java.util.PriorityQueue;

class Solution {
    public long minCost(int m, int n, int[][] waitCost) {
        long[][] dist = new long[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = Long.MAX_VALUE;
            }
        }

        dist[0][0] = (0 + 1) * (0 + 1);

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Long.compare(dist[a[0]][a[1]], dist[b[0]][b[1]]));
        pq.offer(new int[]{0, 0});

        int[][] directions = {{0, 1}, {1, 0}};

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int r = curr[0];
            int c = curr[1];

            long currentCost = dist[r][c];

            if (r == m - 1 && c == n - 1) {
                return currentCost;
            }

            for (int[] dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    long newCost = currentCost + waitCost[r][c] + (nr + 1) * (nc + 1);
                    if (nr == 0 && nc == 0) {
                         newCost = (nr + 1) * (nc + 1);
                    }
                    
                    if (dist[nr][nc] > newCost) {
                        dist[nr][nc] = newCost;
                        pq.offer(new int[]{nr, nc});
                    }
                }
            }
             int nr = r;
             int nc = c;
             long newCost = currentCost + waitCost[r][c];
             if (dist[nr][nc] > newCost){
                 dist[nr][nc] = newCost;
             }
        }

        return dist[m - 1][n - 1];
    }
}