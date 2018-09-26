# -*- coding:utf-8 -*-
class Solution:
    def rectCover(self, number):
        # write code here
        if number == 0:
            return 0
        elif number == 1:
            return 1
        elif number == 2:
            return 2
        else :
            li = [1,2]
            for i in range(2,number):
                li.append(li[i-1]+li[i-2])
            return li[number-1]
