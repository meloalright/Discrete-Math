class Solution:

    def findMedianSortedArrays(self, nums1, nums2):
        m = len(nums1)
        n = len(nums2)

        if m > n :
            return self.findMedianSortedArrays(nums2, nums1)

        k = (m + n - 1) // 2
        l = 0 # moving pointer
        r = min(m, k)

        # binarysearch
        # core
        while l < r:
            half1 = (l + r) // 2
            half2 = k - half1
            if nums1[half1] < nums2[half2]:
                l = half1 + 1
                pass
            else:
                r = half1



        # after binary search, we almost get the median because it must be between
        # these 4 numbers: A[l-1], A[l], B[k-l], and B[k-l+1] 
    
        # if (n+m) is odd, the median is the larger one between A[l-1] and B[k-l].
        # and there are some corner cases we need to take care of.
        a = max(nums1[l-1] if l > 0  else float('-inf'), nums2[k-l] if k-l >= 0 else float('-inf'))

        if (m + n) & 1 == 1:
            return a

        b = min(nums1[l] if l < m else float('inf'), nums2[k-l+1] if k-l+1 < n else float('inf'))
        return (a+b) / 2

s = Solution()
print(s.findMedianSortedArrays([1,2,3,4,5], [6,7,8,9])) # 5
print(s.findMedianSortedArrays([1,2,3,4,5], [6,7,8,9,10])) # 5.5
print(s.findMedianSortedArrays([1,2,3], [4,5,6,7,8,9,10])) # 5.5
print(s.findMedianSortedArrays([1], [2,3,4,5,6,7,8,9,10])) # 5.5
print(s.findMedianSortedArrays([1,2,3,4,5,6,7,8,9,10], [])) # 5.5
