class Solution(object):
    def removeDuplicates(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []

        for ch in s:
            if stack and ch == stack[-1]:
                stack.pop()
            else:
                stack.append(ch)
                
        new =  "".join(stack) 
        return new  
        
