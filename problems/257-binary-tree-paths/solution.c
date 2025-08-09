/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char ***result = malloc(sizeof(char **) * 100);
    *returnSize = 0;
    if (root == NULL) return NULL;
    
    char **paths = malloc(sizeof(char *) * 100);
    int pathIndex = 0;
    
    void traverse(struct TreeNode* node, char* currentPath, int pathLen){
        int len = pathLen;
        char *newPath = malloc(sizeof(char) * (len + 50));
        strcpy(newPath, currentPath);
        char num[10];
        sprintf(num, "%d", node->val);
        strcat(newPath, num);
        
        if(node->left == NULL && node->right == NULL){
            paths[pathIndex++] = strdup(newPath);
        } else {
            if(node->left) {
                strcat(newPath, "->");
                traverse(node->left, newPath, len + strlen(num) + 2);
            }
            if(node->right) {
                if(node->left) newPath = malloc(sizeof(char) * (len + 50));
                else {
                    strcat(newPath, "->");
                }
                strcpy(newPath, currentPath);
                strcat(newPath, num);
                
                strcat(newPath, "->");
                traverse(node->right, newPath, len + strlen(num) + 2);
            }
        }
        free(newPath);
    }
    
    traverse(root, "", 0);
    
    *returnSize = pathIndex;
    char **finalPaths = malloc(sizeof(char*) * (*returnSize));
    for(int i = 0; i < *returnSize; i++){
        finalPaths[i] = paths[i];
    }
    free(paths);
    
    return finalPaths;
}