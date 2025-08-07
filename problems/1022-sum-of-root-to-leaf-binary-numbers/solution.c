/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumRootToLeaf(struct TreeNode* root) {
    int sum = 0;
    
    void dfs(struct TreeNode* node, int current_num) {
        if (!node) {
            return;
        }
        
        current_num = (current_num << 1) | node->val;
        
        if (!node->left && !node->right) {
            sum += current_num;
            return;
        }
        
        dfs(node->left, current_num);
        dfs(node->right, current_num);
    }
    
    dfs(root, 0);
    return sum;
}