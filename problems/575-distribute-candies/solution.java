class Solution {
    public int distributeCandies(int[] candyType) {
        Set<Integer> distinctCandies = new HashSet<>();
        for (int candy : candyType) {
            distinctCandies.add(candy);
        }
        int maxCandies = candyType.length / 2;
        return Math.min(distinctCandies.size(), maxCandies);
    }
}