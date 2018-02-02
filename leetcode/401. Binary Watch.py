class Solution:
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        return ["%d:%02d"% (m,n)
               for m in range(12) for n in range(60)
               if bin(m).count('1')+bin(n).count('1')==num]
