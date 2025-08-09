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
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* prev = nullptr;
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;
            inorder(node->left);
            if (prev) {
                minDiff = min(minDiff, node->val - prev->val);
            }
            prev = node;
            inorder(node->right);
        };
        inorder(root);
        return minDiff;
    }
};