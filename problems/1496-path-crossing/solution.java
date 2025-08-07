class Solution {
    public boolean isPathCrossing(String path) {
        Set<String> visited = new HashSet<>();
        visited.add("0,0");
        int x = 0, y = 0;
        for (char c : path.toCharArray()) {
            if (c == 'N') y++;
            else if (c == 'S') y--;
            else if (c == 'E') x++;
            else x--;
            String coord = x + "," + y;
            if (visited.contains(coord)) return true;
            visited.add(coord);
        }
        return false;
    }
}