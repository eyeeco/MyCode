# -*- coding:utf-8 -*-
class Solution:
    def reOrderArray(self, array):
        # write code here
        li1 = []
        li2 = []
        for num in array:
            if num%2 == 1:
                li1.append(num)
            if num%2 == 0:
                li2.append(num)
        return li1+li2
