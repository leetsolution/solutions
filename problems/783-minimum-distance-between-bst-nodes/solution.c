/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDiffInBST(struct TreeNode* root) {
    int minDiff = INT_MAX;
    int prev = -1;
    struct TreeNode *curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            if(prev != -1){
                minDiff = minDiff < abs(curr->val - prev) ? minDiff : abs(curr->val - prev);
            }
            prev = curr->val;
            curr = curr->right;
        } else {
            struct TreeNode *temp = curr->left;
            while(temp->right != NULL && temp->right != curr){
                temp = temp->right;
            }
            if(temp->right == NULL){
                temp->right = curr;
                curr = curr->left;
            } else {
                temp->right = NULL;
                if(prev != -1){
                    minDiff = minDiff < abs(curr->val - prev) ? minDiff : abs(curr->val - prev);
                }
                prev = curr->val;
                curr = curr->right;
            }
        }
    }
    return minDiff;
}