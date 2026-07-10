class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        s = ""
        while(n>=1):
            s+=str(n%2)
            n//=2

        rev = s[::-1]
        return rev.count("1")