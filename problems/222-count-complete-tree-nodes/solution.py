# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        left_height = 0
        right_height = 0
        left = root.left
        right = root.right
        while left:
            left_height += 1
            left = left.left
        while right:
            right_height += 1
            right = right.right
        if left_height == right_height:
            return (1 << (left_height + 1)) - 1
        else:
            return 1 + self.countNodes(root.left) + self.countNodes(root.right)