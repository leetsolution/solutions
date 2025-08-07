/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize) {
    int* ans = (int*)malloc(num_people * sizeof(int));
    for (int i = 0; i < num_people; i++) {
        ans[i] = 0;
    }
    *returnSize = num_people;
    int give = 1;
    int i = 0;
    while (candies > 0) {
        if (candies >= give) {
            ans[i] += give;
            candies -= give;
            give++;
        } else {
            ans[i] += candies;
            candies = 0;
        }
        i = (i + 1) % num_people;
    }
    return ans;
}