#0ms, Beats 100%
class Solution(object):
    def findDifference(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[List[int]]
        """
        d = set(nums1)
        e = set(nums2)

        return [list(d-e), list(e-d)]

class Solution2(object):
    def findDifference(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[List[int]]
        """
        a, b = [], []
        d, e = set(nums1), set(nums2)
        
        for i in d:
            if i not in e:
                a.append(i)

        for i in e:
            if i not in d:
                b.append(i)

        return [a, b]

        
#48ms, Beats 29.63%
class Solution3(object):
    def findDifference(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[List[int]]
        """
        a, b = [], []
        d, e = {}, {}
        for i in nums1:
            try:
                d[i] += 1
            except:
                d[i] = 1
        for i in nums2:
            try:
                e[i] += 1
            except:
                e[i] = 1
        nums1, nums2 = list(d.keys()), list(e.keys())
        
        for i in d:
            try:
                e[i] += 1
            except KeyError:
                a.append(i)

        for i in e:
            try:
                d[i] += 1
            except KeyError:
                b.append(i)

        return [a, b]
        

class Solution4(object):
    def findDifference(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[List[int]]
        """
        a, b = [], []
        for i in nums1:
            if i not in nums2 and i not in a:
                a.append(i)
        for j in nums2:
            if j not in nums1 and j not in b:
                b.append(j)
        return [a, b]


