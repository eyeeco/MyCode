# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def FindKthToTail(self, head, k):
        # write code here
        p = head
        q = head
        while k and p:
            k -= 1
            p=p.next
        while p and q:
            p=p.next
            q=q.next
        return q if k==0 else None
