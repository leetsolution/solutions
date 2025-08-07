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
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }

    void dfs(TreeNode* root, int currentNum, int& sum) {
        if (!root) return;

        currentNum = (currentNum << 1) | root->val;

        if (!root->left && !root->right) {
            sum += currentNum;
            return;
        }

        dfs(root->left, currentNum, sum);
        dfs(root->right, currentNum, sum);
    }
};