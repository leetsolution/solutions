/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdbool.h>

bool findTarget(struct TreeNode* root, int k) {
    int arr[10000];
    int i = 0;
    struct TreeNode* stack[10000];
    int top = -1;
    struct TreeNode* curr = root;
    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        arr[i++] = curr->val;
        curr = curr->right;
    }
    int left = 0;
    int right = i - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == k) {
            return true;
        } else if (sum < k) {
            left++;
        } else {
            right--;
        }
    }
    return false;
}