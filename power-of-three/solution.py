class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        for i in range(20):
            if 3**i == n:
                return True
        return False