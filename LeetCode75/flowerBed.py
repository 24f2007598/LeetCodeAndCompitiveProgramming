class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        if n == 0: return True
        l = len(flowerbed)
        if l==1 and flowerbed[0] == 0:
            n = n-1
        else:
            for i in range(l):
                if n == 0: break
                if flowerbed[i] == 0:
                    if i == 0:
                        if flowerbed[i+1] == 0: 
                            n = n - 1
                            flowerbed[i] = 1
                        else: pass
                    elif  i == l-1:
                        if flowerbed[i-1] == 0:
                            n = n - 1
                            flowerbed[i] = 1
                    else:
                        if flowerbed[i-1] == 0 and flowerbed[i+1] == 0:
                            n = n -1
                            flowerbed[i] = 1
        if n == 0:
            return True
        return False
