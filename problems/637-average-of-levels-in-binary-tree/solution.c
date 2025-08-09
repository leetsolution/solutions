/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    struct TreeNode **queue = malloc(sizeof(struct TreeNode *) * 10000);
    double *result = malloc(sizeof(double) * 10000);
    int head = 0;
    int tail = 1;
    queue[0] = root;
    int level = 0;
    double sum = 0;
    int count = 0;
    while (head < tail) {
        struct TreeNode *node = queue[head++];
        sum += node->val;
        count++;
        if (node->left) {
            queue[tail++] = node->left;
        }
        if (node->right) {
            queue[tail++] = node->right;
        }
        if (head == tail -1) {
            result[level++] = sum / count;
            sum = 0;
            count = 0;
        }
    }
    *returnSize = level;
    double *finalResult = malloc(sizeof(double) * level);
    for (int i = 0; i < level; i++) {
        finalResult[i] = result[i];
    }
    free(queue);
    free(result);
    return finalResult;
}