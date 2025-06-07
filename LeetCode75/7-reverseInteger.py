#37ms runtime, beats 69.89%
class Solution1:
    def reverse(self, s: int) -> int:
        if s < 0:
            x = -s
        else:
            x = s
        sm = 0
        while x > 0:
            u = x%10
            sm = sm*10 + u
            x = x//10
        
        if s < 0:
            sm = -sm
        if sm < -(2**31) or sm > 2**31-1:
            return 0
        return sm
        
class Solution2:
    def reverse(self, s: int) -> int:
        if s < 0:
            x = -s
        else:
            x = s
        
        x = str(x)[::-1]
        x = int(x)

        if s < 0:
            x = -x
        return x
        
