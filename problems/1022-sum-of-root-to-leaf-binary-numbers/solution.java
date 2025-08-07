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
    public int sumRootToLeaf(TreeNode root) {
        return sumRootToLeafHelper(root, 0);
    }

    private int sumRootToLeafHelper(TreeNode node, int currentNumber) {
        if (node == null) {
            return 0;
        }

        currentNumber = (currentNumber << 1) | node.val;

        if (node.left == null && node.right == null) {
            return currentNumber;
        }

        return sumRootToLeafHelper(node.left, currentNumber) + sumRootToLeafHelper(node.right, currentNumber);
    }
}