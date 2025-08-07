/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isCousins(struct TreeNode* root, int x, int y) {
    if (!root) return false;

    struct TreeNode *x_parent = NULL;
    struct TreeNode *y_parent = NULL;
    int x_depth = -1;
    int y_depth = -1;

    struct TreeNode *queue[100];
    int head = 0;
    int tail = 0;
    queue[tail++] = root;
    int level = 0;

    while (head < tail) {
        int level_size = tail - head;
        for (int i = 0; i < level_size; i++) {
            struct TreeNode *curr = queue[head++];

            if (curr->left) {
                if (curr->left->val == x) {
                    x_parent = curr;
                    x_depth = level + 1;
                }
                if (curr->left->val == y) {
                    y_parent = curr;
                    y_depth = level + 1;
                }
                queue[tail++] = curr->left;
            }
            if (curr->right) {
                if (curr->right->val == x) {
                    x_parent = curr;
                    x_depth = level + 1;
                }
                if (curr->right->val == y) {
                    y_parent = curr;
                    y_depth = level + 1;
                }
                queue[tail++] = curr->right;
            }
        }
        level++;
    }

    return (x_depth == y_depth) && (x_parent != y_parent);
}