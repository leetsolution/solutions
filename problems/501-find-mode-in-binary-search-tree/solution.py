# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        
        count = {}
        max_count = 0
        
        def inorder(node):
            nonlocal max_count
            if node:
                inorder(node.left)
                if node.val in count:
                    count[node.val] += 1
                else:
                    count[node.val] = 1
                max_count = max(max_count, count[node.val])
                inorder(node.right)
        
        inorder(root)
        
        result = []
        for val, c in count.items():
            if c == max_count:
                result.append(val)
        return result