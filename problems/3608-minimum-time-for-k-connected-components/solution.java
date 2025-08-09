class Solution {
    public int minTime(int n, int[][] edges, int k) {
        if (k <= 1) {
            return 0;
        }

        int left = 0;
        int right = 0;
        for (int[] edge : edges) {
            right = Math.max(right, edge[2]);
        }

        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int components = countComponents(n, edges, mid);

            if (components >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (countComponents(n, edges, 0) >= k) return 0;

        return ans;
    }

    private int countComponents(int n, int[][] edges, int time) {
        UnionFind uf = new UnionFind(n);
        for (int[] edge : edges) {
            if (edge[2] > time) {
                uf.union(edge[0], edge[1]);
            }
        }
        return uf.count();
    }

    private class UnionFind {
        private int[] parent;
        private int count;

        public UnionFind(int n) {
            parent = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
            count = n;
        }

        public int find(int i) {
            if (parent[i] == i) {
                return i;
            }
            return parent[i] = find(parent[i]);
        }

        public void union(int i, int j) {
            int rootI = find(i);
            int rootJ = find(j);
            if (rootI != rootJ) {
                parent[rootI] = rootJ;
                count--;
            }
        }

        public int count() {
            return count;
        }
    }
}