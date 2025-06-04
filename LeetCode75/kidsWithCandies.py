class Solution(object):
    def kidsWithCandies(self, candies, extraCandies):
        """
        :type candies: List[int]
        :type extraCandies: int
        :rtype: List[bool]
        """
        mx = max(candies)
        boolarr = []
        for i in candies:
            if i+extraCandies >= mx:
                boolarr.append(True)
            else:
                boolarr.append(False)
        return boolarr
        
