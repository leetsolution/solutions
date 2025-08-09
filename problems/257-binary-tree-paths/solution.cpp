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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == nullptr) return result;
        
        function<void(TreeNode*, string)> dfs = [&](TreeNode* node, string path) {
            path += to_string(node->val);
            if (node->left == nullptr && node->right == nullptr) {
                result.push_back(path);
                return;
            }
            if (node->left) {
                dfs(node->left, path + "->");
            }
            if (node->right) {
                dfs(node->right, path + "->");
            }
        };
        
        dfs(root, "");
        return result;
    }
};