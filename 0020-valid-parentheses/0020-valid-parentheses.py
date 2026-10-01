class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        d = {
            ")" : "(",
            "}" : "{",
            "]" : "["
        }
        stack = []

        for ch in s:
            if ch in d.values() :
                stack.append(ch)

           # else:
              #  return False
            if stack ==[]:
                return False
            elif ch in d.keys():
             p = stack.pop()
             if d[ch] != p:
                return False
        if stack == []:
            return True
        else:
            return False
