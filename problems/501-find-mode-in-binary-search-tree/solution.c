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
int* findMode(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int maxCount = 0;
    int currentCount = 0;
    int currentVal = 0;
    int* modes = NULL;
    int modesSize = 0;
    int modesIndex = 0;

    struct TreeNode* stack[10000];
    int top = -1;
    struct TreeNode* curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            top++;
            stack[top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        if (currentVal == curr->val) {
            currentCount++;
        } else {
            currentVal = curr->val;
            currentCount = 1;
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
            modesSize = 1;
            modes = (int*)malloc(sizeof(int) * modesSize);
            modes[0] = curr->val;
            modesIndex = 0;
        } else if (currentCount == maxCount) {
            modesSize++;
            modes = (int*)realloc(modes, sizeof(int) * modesSize);
            modes[++modesIndex] = curr->val;
        }
        curr = curr->right;
    }

    *returnSize = modesSize;
    return modes;
}