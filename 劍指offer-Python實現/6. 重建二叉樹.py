# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回构造的TreeNode根节点
    def construct(self, pre, tin, preindex, instart, inend):
        if preindex<len(pre) and instart<=inend:
            head = TreeNode(pre[preindex])
            hindex = tin.index(pre[preindex])
            head.left = self.construct(pre, tin, preindex+1, instart, hindex-1)
            head.right = self.construct(pre, tin, preindex+1+hindex-instart, hindex+1, inend)
            return head
        return None
    def reConstructBinaryTree(self, pre, tin):
        # write code here
        return self.construct(pre, tin, 0, 0, len(tin)-1)
