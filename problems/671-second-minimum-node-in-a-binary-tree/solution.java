/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int findSecondMinimumValue(TreeNode root) {
        long min1 = Long.MAX_VALUE;
        long min2 = Long.MAX_VALUE;

        dfs(root, min1, min2);

        return min2 == Long.MAX_VALUE ? -1 : (int)min2;
    }


    private void dfs(TreeNode node, long min1, long min2){
        if(node == null) return;

        if(node.val < min1){
            min2 = min1;
            min1 = node.val;
        } else if (node.val < min2 && node.val > min1){
            min2 = node.val;
        }

        dfs(node.left, min1, min2);
        dfs(node.right, min1, min2);
    }
}