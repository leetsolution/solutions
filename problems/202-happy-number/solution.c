#include <stdbool.h>

bool isHappy(int n) {
    int slow = n;
    int fast = n;

    do {
        int sum_slow = 0;
        while (slow > 0) {
            int digit = slow % 10;
            sum_slow += digit * digit;
            slow /= 10;
        }
        slow = sum_slow;

        int sum_fast = 0;
        int temp = fast;
        for (int i = 0; i < 2; i++) {
            sum_fast = 0;
            while (temp > 0) {
                int digit = temp % 10;
                sum_fast += digit * digit;
                temp /= 10;
            }
            temp = sum_fast;
        }
        fast = temp;

    } while (slow != fast);

    return slow == 1;
}