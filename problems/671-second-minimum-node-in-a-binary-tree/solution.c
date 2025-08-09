/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findSecondMinimumValue(struct TreeNode* root) {
    long min1 = (long)root->val;
    long min2 = (long)INT_MAX;
    
    if(root->left){
        long leftVal = (long)root->left->val;
        if(leftVal > min1){
            min2 = min(min2,leftVal);
        } else {
            min2 = min(min2,findSecondMinimumValue(root->left));
        }
    }
    if(root->right){
        long rightVal = (long)root->right->val;
        if(rightVal > min1){
            min2 = min(min2,rightVal);
        } else {
            min2 = min(min2,findSecondMinimumValue(root->right));
        }
    }
    
    if(min2 == (long)INT_MAX) return -1;
    return (int)min2;
}