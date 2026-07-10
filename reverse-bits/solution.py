class Solution(object):
    def reverseBits(self, n):
        """
        :type n: int
        :rtype: int
        """
        s = ""
        for i in range(32):
            s+=str(n%2)
            n//=2
        
        value = 0
        for i in range (32):
            value+=int(s[-i-1]) * 2**(i)
        return value
