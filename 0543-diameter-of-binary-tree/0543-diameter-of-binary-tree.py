# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.max_diameter = 0

        def depth(node):
            if not node:
                return 0
            left = depth(node.left)
            right = depth(node.right)
            # aktualizujemy maksymalną średnicę przy przechodzeniu przez ten węzeł
            self.max_diameter = max(self.max_diameter, left + right)
            # zwracamy wysokość drzewa
            return max(left, right) + 1

        depth(root)
        return self.max_diameter