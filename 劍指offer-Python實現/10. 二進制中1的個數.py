# -*- coding:utf-8 -*-
class Solution:
    def NumberOf1(self, n):
        # write code here
        t = 0
        if n < 0:
            n += pow(2,32)
        while n:
            n = n&(n-1)
            t += 1
        return t
