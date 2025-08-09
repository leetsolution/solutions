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
#include <stdlib.h>

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = NULL;
    *returnSize = 0;
    if (!root) return result;

    int capacity = 100;
    result = (int*)malloc(capacity * sizeof(int));

    struct TreeNode* stack[100];
    int top = -1;
    struct TreeNode* curr = root;

    while (curr || top != -1) {
        while (curr) {
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top--];
        result[(*returnSize)++] = curr->val;

        if (*returnSize >= capacity) {
            capacity *= 2;
            result = (int*)realloc(result, capacity * sizeof(int));
        }
        
        curr = curr->right;
    }

    return result;
}