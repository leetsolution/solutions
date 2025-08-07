# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        def inorder(o, c):
            if not o:
                return None
            
            res = inorder(o.left, c.left)
            if res:
                return res
            
            if o == target:
                return c
            
            return inorder(o.right, c.right)
        
        return inorder(original, cloned)