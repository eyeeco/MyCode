# -*- coding:utf-8 -*-
class Solution:
    def Fibonacci(self, n):
        # write code here
        if n == 0:
            return 0
        elif n == 1:
            return 1
        else :
            li = [0,1]
            for i in range(2,n+1):
                li.append(li[i-1]+li[i-2])
            return li[n]
