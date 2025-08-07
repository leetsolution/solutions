/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int i=0;
    int arr1[200];
    int arr2[200];
    struct TreeNode* curr;
    
    
    
    void getLeaf(struct TreeNode* root,int arr[],int *i){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            arr[(*i)++] = root->val;
            return;
        }
        getLeaf(root->left,arr,i);
        getLeaf(root->right,arr,i);
    }
    
    
    int j=0;
    getLeaf(root1,arr1,&j);
    int k=0;
    getLeaf(root2,arr2,&k);
    
    if(j!=k) return false;
    
    for(int z=0;z<j;z++){
        if(arr1[z]!=arr2[z]) return false;
    }
    return true;
    
}