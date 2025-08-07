import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Map;

class Solution {
    public int minDeletion(String s, int k) {
        Map<Character, Integer> charCounts = new HashMap<>();
        for (char c : s.toCharArray()) {
            charCounts.put(c, charCounts.getOrDefault(c, 0) + 1);
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int count : charCounts.values()) {
            pq.offer(count);
        }

        int distinctChars = charCounts.size();
        int deletions = 0;

        while (distinctChars > k) {
            deletions += pq.poll();
            distinctChars--;
        }

        return deletions;
    }
}