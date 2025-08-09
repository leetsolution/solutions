/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    int leftHeight = 0, rightHeight = 0;
    struct TreeNode *left = root, *right = root;
    while (left) {
        leftHeight++;
        left = left->left;
    }
    while (right) {
        rightHeight++;
        right = right->right;
    }
    if (leftHeight == rightHeight) return (1 << leftHeight) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}