/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findTilt(struct TreeNode* root) {
    int tilt = 0;
    if (root == NULL) return 0;
    int leftSum = findTilt(root->left);
    int rightSum = findTilt(root->right);
    tilt += abs(leftSum - rightSum);
    return leftSum + rightSum + root->val;

}