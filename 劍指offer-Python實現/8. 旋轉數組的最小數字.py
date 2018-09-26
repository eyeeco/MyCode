# -*- coding:utf-8 -*-
class Solution:
    def minNumberInRotateArray(self, rotateArray):
        # write code here
        left = 0
        right =len(rotateArray)-1
        while left<right:
            mid = (left + right)//2
            if rotateArray[mid]<rotateArray[right]:
                right = mid
            elif rotateArray[mid] == rotateArray[right]:
                right = right -1
            else:
                left = mid + 1
        return rotateArray[left]
        
