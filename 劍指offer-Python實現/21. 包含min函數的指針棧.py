# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.li1 = []
        self.li2 = []

    def push(self, node):
        # write code here
        self.li1.append(node)
        if len(self.li2) == 0:
            self.li2.append(node)
        else:
            if node<self.li2[-1]:
                self.li2.append(node)

    def pop(self):
        # write code here
        if self.li1[-1] == self.li2[-1]:
            self.li2.pop()
        self.li1.pop()
    def top(self):
        # write code here
        return self.li1[-1]

    def min(self):
        # write code here
        return self.li2[-1]
