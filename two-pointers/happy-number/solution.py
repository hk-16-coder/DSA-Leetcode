class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n == 1 or n==7:
            return True
        if n<10:
            return False
        s = str(n)

        l = len(s)
        sum = 0
        for i in range (l):
            sum+=int(s[i])**2

        return Solution().isHappy(int(sum))

