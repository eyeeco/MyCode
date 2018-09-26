# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # 返回合并后列表
    def Merge(self, pHead1, pHead2):
        # write code here
        head = ListNode(0)
        t = head
        while pHead1 and pHead2:
            if pHead1.val<pHead2.val:
                p = pHead1
                pHead1 = pHead1.next
                t.next = p
                t = t.next
            else:
                p = pHead2
                pHead2 = pHead2.next
                t.next = p
                t = t.next
        while pHead1:
            p = pHead1
            pHead1 = pHead1.next
            t.next = p
            t = t.next
        while pHead2:
            p = pHead2
            pHead2 = pHead2.next
            t.next = p
            t = t.next
        return head.next
