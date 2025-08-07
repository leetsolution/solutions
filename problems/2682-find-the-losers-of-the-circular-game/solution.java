class Solution {
    public int[] circularGameLosers(int n, int k) {
        boolean[] visited = new boolean[n];
        int current = 0;
        int turn = 1;
        visited[current] = true;
        while (true) {
            int next = (current + turn * k) % n;
            if (visited[next]) {
                break;
            }
            visited[next] = true;
            current = next;
            turn++;
        }
        int count = 0;
        for (boolean v : visited) {
            if (!v) {
                count++;
            }
        }
        int[] losers = new int[count];
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                losers[index++] = i + 1;
            }
        }
        return losers;
    }
}