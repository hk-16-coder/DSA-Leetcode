class Solution(object):
    def isUgly(self, n):
        """
        :type n: int
        :rtype: bool
        """
        l = [2,3,5]
        if n<=0:
            return False
        for i in l:
            while n%i == 0:
                n//=i
        if n == 1 :
            return True
        else:
            return False
        