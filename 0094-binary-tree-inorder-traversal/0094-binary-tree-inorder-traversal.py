# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __traverse(self, node: Optional[TreeNode], solution: List[TreeNode]) -> None:
        if node is None: 
            return
        self.__traverse(node.left, solution)
        solution.append(node.val)
        self.__traverse(node.right, solution)


    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        solution = []
        self.__traverse(root, solution)
        return solution