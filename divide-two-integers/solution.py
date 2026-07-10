class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if (dividend>0 and divisor>0) or (dividend<0 and        divisor<0):
            quotient = dividend//divisor
            if quotient>(2**31) - (1):
                return (2**31) - 1
            else:
                 return quotient
        else:
            quotient =  -(abs(dividend)/abs(divisor))
            if quotient<-2**31:
                return -2**31
            else:
                 return quotient
            

        