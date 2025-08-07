import java.util.*;

class Solution {
    // Generate prime numbers up to 50000 using Sieve of Eratosthenes
    public int[] primeNumbers() {
        int MAX_NUM = 10000;
        int[] prime = new int[5 * MAX_NUM + 1];
        int n = prime.length;

        Arrays.fill(prime, 1);
        prime[0] = prime[1] = 0;

        for (int i = 2; i * i < n; i++) {
            if (prime[i] == 1) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = 0;
                }
            }
        }
        return prime;
    }

    // Maintain min and max deques for current window
    public void insertPrimeDQ(Deque<Integer> minDQ, Deque<Integer> maxDQ, int[] nums, int index) {
        while (!minDQ.isEmpty() && nums[minDQ.peekLast()] > nums[index]) {
            minDQ.removeLast();
        }
        minDQ.addLast(index);

        while (!maxDQ.isEmpty() && nums[maxDQ.peekLast()] < nums[index]) {
            maxDQ.removeLast();
        }
        maxDQ.addLast(index);
    }

    public int primeSubarray(int[] nums, int k) {
        int[] prime = primeNumbers(); // get all primes up to 50000

        Deque<Integer> minDQ = new ArrayDeque<>();
        Deque<Integer> maxDQ = new ArrayDeque<>();
        Deque<Integer> primeDQ = new ArrayDeque<>();

        int left = 0;
        int prevPrime = 0;
        int result = 0;
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            int val = nums[i];

            if (val < prime.length && prime[val] == 1) {
                insertPrimeDQ(minDQ, maxDQ, nums, i);

                if (!primeDQ.isEmpty()) {
                    prevPrime = primeDQ.peekLast();
                }
                primeDQ.addLast(i);

                // Shrink window if prime gap exceeds k
                while (!minDQ.isEmpty() && !maxDQ.isEmpty() &&
                       nums[maxDQ.peekFirst()] - nums[minDQ.peekFirst()] > k) {

                    int removeIdx = primeDQ.removeFirst();
                    left = removeIdx + 1;

                    if (!minDQ.isEmpty() && minDQ.peekFirst() <= removeIdx) minDQ.removeFirst();
                    if (!maxDQ.isEmpty() && maxDQ.peekFirst() <= removeIdx) maxDQ.removeFirst();
                }
            }

            if (primeDQ.size() >= 2) {
                result += prevPrime - left + 1;
            }
        }

        return result;
    }
}
