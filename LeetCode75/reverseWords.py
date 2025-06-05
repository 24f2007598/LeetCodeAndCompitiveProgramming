class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = s.strip()

        words = s.split(' ')

        words = words[::-1]
        words = [i.strip() for i in words if i != '']

        return ' '.join(words)
        
