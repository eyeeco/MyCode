# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.li1 = []
        self.li2 = []

    def push(self, node):
        # write code here
        self.li1.append(node)
    def pop(self):
        # return xx
        if self.li2:
            return self.li2.pop()
        else:
            while self.li1:
                self.li2.append(self.li1.pop())
            return self.li2.pop()
