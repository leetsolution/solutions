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
    vector<int> findMode(TreeNode* root) {
        map<int, int> count;
        vector<int> modes;
        int maxCount = 0;
        function<void(TreeNode*)> traverse = [&](TreeNode* node) {
            if (node == nullptr) return;
            count[node->val]++;
            traverse(node->left);
            traverse(node->right);
        };
        traverse(root);
        for (auto const& [val, c] : count) {
            if (c > maxCount) {
                modes.clear();
                modes.push_back(val);
                maxCount = c;
            } else if (c == maxCount) {
                modes.push_back(val);
            }
        }
        return modes;
    }
};