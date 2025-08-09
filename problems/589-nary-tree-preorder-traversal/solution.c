/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorder(struct Node* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int size = 0;
    struct Node* stack[10000];
    int top = -1;
    int* result = (int*)malloc(10000 * sizeof(int));

    stack[++top] = root;
    while (top >= 0) {
        struct Node* node = stack[top--];
        result[size++] = node->val;
        for (int i = node->numChildren - 1; i >= 0; i--) {
            stack[++top] = node->children[i];
        }
    }
    *returnSize = size;
    return result;
}