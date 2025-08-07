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
    public boolean isCousins(TreeNode root, int x, int y) {
        int xDepth = -1;
        int yDepth = -1;
        TreeNode xParent = null;
        TreeNode yParent = null;

        java.util.Queue<TreeNode> queue = new java.util.LinkedList<>();
        java.util.Queue<Integer> depthQueue = new java.util.LinkedList<>();

        queue.offer(root);
        depthQueue.offer(0);

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            int depth = depthQueue.poll();

            if (node.left != null) {
                if (node.left.val == x) {
                    xDepth = depth + 1;
                    xParent = node;
                }
                if (node.left.val == y) {
                    yDepth = depth + 1;
                    yParent = node;
                }
                queue.offer(node.left);
                depthQueue.offer(depth + 1);
            }

            if (node.right != null) {
                if (node.right.val == x) {
                    xDepth = depth + 1;
                    xParent = node;
                }
                if (node.right.val == y) {
                    yDepth = depth + 1;
                    yParent = node;
                }
                queue.offer(node.right);
                depthQueue.offer(depth + 1);
            }

            if (xDepth != -1 && yDepth != -1) {
                break;
            }
        }

        return xDepth == yDepth && xParent != yParent;
    }
}