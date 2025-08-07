/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool evaluateTree(struct TreeNode* root) {
    if (root->left == NULL && root->right == NULL) {
        return root->val == 1;
    }

    bool left_val = evaluateTree(root->left);
    bool right_val = evaluateTree(root->right);

    if (root->val == 2) {
        return left_val || right_val;
    } else {
        return left_val && right_val;
    }
}