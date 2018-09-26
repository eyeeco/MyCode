# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def isSame(self, root1, root2):
        if not root2:
            return True
        elif not root1:
            return False
        else:
            return root1.val == root2.val and self.isSame(root1.left,root2.left) and self.isSame(root1.right,root2.right)

    def HasSubtree(self, pRoot1, pRoot2):
        # write code here
        if not pRoot1 or not pRoot2:
            return False
        return self.isSame(pRoot1,pRoot2) or self.HasSubtree(pRoot1.left,pRoot2) or self.HasSubtree(pRoot1.right,pRoot2)
