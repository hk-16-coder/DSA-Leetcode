class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        l = nums1 + nums2
        l.sort()
        if len(l)%2!=0:
            return l[len(l)//2 ]
        elif len(l)%2==0:
            mid = len(l)//2
            return (l[mid-1] + l[mid]) / 2.0
