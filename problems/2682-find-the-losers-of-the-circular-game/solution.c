/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* circularGameLosers(int n, int k, int* returnSize) {
    int* received = (int*)calloc(n, sizeof(int));
    int current = 0;
    int move = 1;
    received[0] = 1;

    while (1) {
        current = (current + move * k) % n;
        if (current < 0) current += n;

        if (received[current] == 1) {
            break;
        }

        received[current] = 1;
        move++;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (received[i] == 0) {
            count++;
        }
    }

    int* losers = (int*)malloc(count * sizeof(int));
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (received[i] == 0) {
            losers[index++] = i + 1;
        }
    }

    *returnSize = count;
    return losers;
}