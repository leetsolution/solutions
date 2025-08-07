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
    TreeNode head = new TreeNode();
    TreeNode tail = head;
    public TreeNode increasingBST(TreeNode root) {
        inorder(root);
        return head.right;
    }
    public void inorder(TreeNode node){
        if(node == null) return;
        inorder(node.left);
        tail.right = new TreeNode(node.val);
        tail = tail.right;
        inorder(node.right);
    }
}