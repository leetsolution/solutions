import java.util.*;

class Solution {
    public int minJumps(int[] nums) {
        int n = nums.length;
        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        int[] dist = new int[n];
        Arrays.fill(dist, -1);
        dist[0] = 0;
        boolean[] visited = new boolean[n];
        visited[0] = true;

        List<Integer> primes = sieve(100001);
        Map<Integer, List<Integer>> primeIndices = new HashMap<>();

        for (int i = 0; i < n; i++) {
            for (int p : primes) {
                if (p > nums[i]) break;
                if (nums[i] % p == 0) {
                    primeIndices.computeIfAbsent(p, k -> new ArrayList<>()).add(i);
                }
            }
        }

        while (!q.isEmpty()) {
            int u = q.poll();

            if (u == n - 1) {
                return dist[u];
            }

            int[] neighbors = {u + 1, u - 1};
            for (int v : neighbors) {
                if (v >= 0 && v < n && !visited[v]) {
                    dist[v] = dist[u] + 1;
                    visited[v] = true;
                    q.offer(v);
                }
            }

            if (primes.contains(nums[u])) {
                int prime = nums[u];
                if (primeIndices.containsKey(prime)) {
                    for (int v : primeIndices.get(prime)) {
                        if (v != u && !visited[v]) {
                            dist[v] = dist[u] + 1;
                            visited[v] = true;
                            q.offer(v);
                        }
                    }
                    primeIndices.remove(prime);
                }
            }
        }

        return dist[n - 1];
    }

    private List<Integer> sieve(int n) {
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;

        for (int p = 2; p * p <= n; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    isPrime[i] = false;
                }
            }
        }

        List<Integer> primes = new ArrayList<>();
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.add(i);
            }
        }
        return primes;
    }
}