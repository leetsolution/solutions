/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorder(struct Node* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int count = 0;
    int* values = NULL;
    
    if (root->numChildren > 0) {
        struct Node** children = root->children;
        int i;
        int* childValues;
        int childReturnSize;

        for (i = 0; i < root->numChildren; i++) {
            childValues = postorder(children[i], &childReturnSize);
            if (childValues) {
                values = realloc(values, (count + childReturnSize) * sizeof(int));
                memcpy(values + count, childValues, childReturnSize * sizeof(int));
                count += childReturnSize;
                free(childValues);
            }
        }
    }


    values = realloc(values, (count + 1) * sizeof(int));
    values[count] = root->val;
    count++;

    *returnSize = count;
    return values;
}