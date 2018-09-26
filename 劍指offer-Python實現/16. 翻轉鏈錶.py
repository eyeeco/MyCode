# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # 返回ListNode
    def ReverseList(self, pHead):
        # write code here
        head = ListNode(0)
        while pHead:
            p = pHead
            pHead = pHead.next
            p.next = head.next
            head.next = p
        return head.next
