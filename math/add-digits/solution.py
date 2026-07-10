class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        s = str(num)
        
        while True:
         val = 0
         for i in range(len(s)):
            val+=int(s[i])
         if val<10:
            return val
            
         else:
          s = str(val)
