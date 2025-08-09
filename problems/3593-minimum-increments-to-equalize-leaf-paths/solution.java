import java.util.*;

class Solution {
    public int minIncrease(int n, int[][] edges, int[] cost) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }

        List<Integer> leafPathSums = new ArrayList<>();
        dfs(0, adj, cost, 0, new boolean[n], leafPathSums);

        int maxPathSum = 0;
        for (int sum : leafPathSums) {
            maxPathSum = Math.max(maxPathSum, sum);
        }

        int increases = 0;
        for (int sum : leafPathSums) {
            increases += (maxPathSum - sum);
        }

        return increases;
    }

    private void dfs(int node, List<List<Integer>> adj, int[] cost, int currentSum, boolean[] visited, List<Integer> leafPathSums) {
        visited[node] = true;
        currentSum += cost[node];

        boolean isLeaf = true;
        for (int neighbor : adj.get(node)) {
            if (!visited[neighbor]) {
                isLeaf = false;
                dfs(neighbor, adj, cost, currentSum, visited.clone(), leafPathSums);
            }
        }

        if (isLeaf) {
            leafPathSums.add(currentSum);
        }
    }
}