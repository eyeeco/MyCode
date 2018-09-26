# -*- coding:utf-8 -*-
class Solution:
    def Power(self, base, exponent):
        # write code here
        if exponent < 0:
            base = 1/base
            exponent = -exponent
        if exponent == 0:
            return 1
        elif exponent == 1:
            return base
        elif exponent%2 == 0:
            return pow(self.Power(base,exponent/2),2)
        else:
            return base*pow(self.Power(base,exponent//2),2)
