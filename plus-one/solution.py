class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        a = ""
        for i in digits:
            a+= str(i)
        b = int(a)
        b+=1
        c = str(b)
        l =[]
        for i in range(len(c)):
            l.append(int(c[i])) 
        
        return l