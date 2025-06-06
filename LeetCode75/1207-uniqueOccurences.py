#0 ms, Beats 100.00%
class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        d = {}
        for i in arr:
            try:
                d[i] += 1
            except KeyError:
                d[i] = 1
        
        e = {}
        for i in d:
            try:
                e[d[i]] += 1
                return False
            except KeyError:
                e[d[i]] = 1
        return True
