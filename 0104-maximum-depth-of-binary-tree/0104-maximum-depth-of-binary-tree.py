# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        # BASE CASE:
        # If the tree is empty (we reached past a leaf node), the depth is 0.
        if root is None:
            return 0
        
        # RECURSIVE STEP:
        # 1. Find the depth of the left sub-tree recursively
        left_depth = self.maxDepth(root.left)
        
        # 2. Find the depth of the right sub-tree recursively
        right_depth = self.maxDepth(root.right)
        
        # 3. The depth of the current node is the MAX of the two children,
        # plus 1 to account for the current node itself.
        return max(left_depth, right_depth) + 1