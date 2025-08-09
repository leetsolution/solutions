/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b) {
    return a > b ? a : b;
}

int depth(struct TreeNode* node, int* diameter) {
    if (node == NULL) {
        return 0;
    }
    int leftDepth = depth(node->left, diameter);
    int rightDepth = depth(node->right, diameter);
    *diameter = max(*diameter, leftDepth + rightDepth);
    return max(leftDepth, rightDepth) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;
    depth(root, &diameter);
    return diameter;
}