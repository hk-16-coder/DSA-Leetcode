class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        d= {"I" : 1,
            "V" : 5,
            "X" : 10,
            "L" : 50,
            "C" : 100,
            "D" : 500,
            "M" : 1000
        }
        value = 0
        i = 0

        if len(s)>=2:
         while(i<len(s)-1):
            if d[s[i]] >=d[s[i+1]]:
                value+=d[s[i]]
                i+=1
            else:
                value+=(d[s[i+1]]-d[s[i]])
                i+=2
         
         if d[s[-2]] >= d[s[-1]]:
            value+=d[s[-1]]
        elif len(s) == 1:
            value = d[s[0]]

        return value