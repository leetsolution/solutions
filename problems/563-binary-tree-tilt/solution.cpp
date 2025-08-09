/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findTilt(TreeNode* root) {
        int tilt = 0;
        dfs(root, tilt);
        return tilt;
    }

    int dfs(TreeNode* node, int& tilt) {
        if (!node) return 0;
        int leftSum = dfs(node->left, tilt);
        int rightSum = dfs(node->right, tilt);
        tilt += abs(leftSum - rightSum);
        return leftSum + rightSum + node->val;
    }
};