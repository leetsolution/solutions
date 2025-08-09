import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Set;

class Solution {
    public long sumOfLargestPrimes(String s) {
        Set<Long> primes = new HashSet<>();
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                String sub = s.substring(i, j + 1);
                if (sub.startsWith("0") && sub.length() > 1) {
                    continue;
                }
                long num = Long.parseLong(sub);
                if (isPrime(num)) {
                    primes.add(num);
                }
            }
        }

        PriorityQueue<Long> pq = new PriorityQueue<>();
        for (long prime : primes) {
            pq.offer(prime);
            if (pq.size() > 3) {
                pq.poll();
            }
        }

        long sum = 0;
        while (!pq.isEmpty()) {
            sum += pq.poll();
        }

        if (primes.size() == 1 && sum == 1) return 0;
        return sum;
    }

    private boolean isPrime(long n) {
        if (n <= 1) {
            return false;
        }
        if (n <= 3) {
            return true;
        }
        if (n % 2 == 0 || n % 3 == 0) {
            return false;
        }
        for (int i = 5; i * i <= n; i = i + 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}