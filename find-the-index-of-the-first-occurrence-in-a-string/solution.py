class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        l = haystack.find(needle)
        if l>=0:
         return l
        else:
         return -1


