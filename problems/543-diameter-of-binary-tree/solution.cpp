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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        helper(root, diameter);
        return diameter;
    }

    int helper(TreeNode* node, int& diameter) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = helper(node->left, diameter);
        int rightHeight = helper(node->right, diameter);

        diameter = max(diameter, leftHeight + rightHeight);

        return max(leftHeight, rightHeight) + 1;
    }
};