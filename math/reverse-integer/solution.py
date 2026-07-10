class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        
        if x>=0:
            s = str(x)
            new =""
            if s[-1] !=0:
             for i in range(-1,-len(s)-1,-1):
                new+=s[i]
            elif s[-1] == 0:
             for i in range(-2,-len(s)-1,-1):
                new+=s[i]
            if  int(new)>= (2**31) -1:
             return 0
            else:
                 return int(new)
            
        if x<0:
            s = str(x)
            new = "-"
            
            if s[-1] !=0:
             for i in range(-1,-len(s),-1):
                new+=s[i]
            elif s[-1] == 0:
             for i in range(-2,-len(s),-1):
                new+=s[i]
            if int(new)<= -2**31 :
             return 0
            else:
             return int(new)