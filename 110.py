# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def judge(self, root):
        if root == None:
            return True, 0
        leftbal, leftheight = self.judge(root.left)
        rightbal, rightheight = self.judge(root.right)
        return leftbal and rightbal and abs(leftheight-rightheight) <= 1, max(leftheight, rightheight) + 1

    def isBalanced(self, root: TreeNode) -> bool:
        bal, _ = self.judge(root)
        return bal

root = TreeNode(10)
root.left = TreeNode(12)
root.right = TreeNode(11)
print(Solution().judge(root))
