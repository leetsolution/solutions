/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* increasingBST(struct TreeNode* root) {
    struct TreeNode *dummy = malloc(sizeof(struct TreeNode));
    dummy->right = NULL;
    struct TreeNode *cur = dummy;
    struct TreeNode *prev = NULL;
    
    
    struct TreeNode* stack[101];
    int top = -1;
    
    while(root || top != -1){
        while(root){
            stack[++top] = root;
            root = root->left;
        }
        root = stack[top--];
        
        cur->right = root;
        cur = cur->right;
        cur->left = NULL;
        root = root->right;

    }
    return dummy->right;
}