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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> s;
        TreeNode* lastVisited = nullptr;
        TreeNode* curr = root;

        while (!s.empty() || curr) {
            if (curr) {
                s.push(curr);
                curr = curr->left;
            } else {
                TreeNode* topNode = s.top();
                if (topNode->right && lastVisited != topNode->right) {
                    curr = topNode->right;
                } else {
                    result.push_back(topNode->val);
                    lastVisited = topNode;
                    s.pop();
                }
            }
        }

        return result;
    }
};