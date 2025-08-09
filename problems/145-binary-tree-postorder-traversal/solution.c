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
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(101 * sizeof(int));
    *returnSize = 0;

    if (root == NULL) {
        return result;
    }

    struct TreeNode* stack[101];
    int top = -1;
    struct TreeNode* lastVisited = NULL;
    struct TreeNode* curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top];

        if (curr->right != NULL && curr->right != lastVisited) {
            curr = curr->right;
        } else {
            result[(*returnSize)++] = curr->val;
            top--;
            lastVisited = curr;
            curr = NULL;
        }
    }

    return result;
}