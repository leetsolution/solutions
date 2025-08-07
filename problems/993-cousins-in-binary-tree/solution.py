# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        x_parent, y_parent = None, None
        x_depth, y_depth = None, None

        def dfs(node, parent, depth):
            nonlocal x_parent, y_parent, x_depth, y_depth

            if not node:
                return

            if node.val == x:
                x_parent = parent
                x_depth = depth
            elif node.val == y:
                y_parent = parent
                y_depth = depth

            dfs(node.left, node, depth + 1)
            dfs(node.right, node, depth + 1)

        dfs(root, None, 0)

        return x_depth == y_depth and x_parent != y_parent