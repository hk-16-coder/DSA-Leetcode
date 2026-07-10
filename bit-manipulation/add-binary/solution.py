class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        if a == "0" and b == "0":
            return "0"
        a_ = 0
        for i in range(1,len(a)+1):
            a_+= int(a[-i]) * (2**(i-1))
        
        b_ = 0
        for i in range(1,len(b)+1):
            b_+= int(b[-i]) * (2**(i-1))
        c = a_ + b_
        c_ =""
        

        while(c>=1):
            if c%2 == 0 :
                c_+="0"
                c = c//2
            else :   
                c_+="1"
                c=c//2 
        rev = c_[::-1] 
        return rev