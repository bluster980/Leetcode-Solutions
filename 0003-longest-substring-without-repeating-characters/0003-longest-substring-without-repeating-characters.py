class Solution(object):
    def lengthOfLongestSubstring(self, s):
        left = 0
        right = 0
        chars = [-1] * 256
        maxx = 0
        while right < len(s):
            if chars[ord(s[right])] != -1:
                left = max(left, chars[ord(s[right])] + 1)
            chars[ord(s[right])] = right
            maxx = max(maxx, right - left + 1)
            right += 1
        return maxx
