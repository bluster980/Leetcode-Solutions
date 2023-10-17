class Solution(object):
    def lengthOfLongestSubstring(self, s):
        left = 0
        right = 0
        chars = {}
        maxx = 0
        while right < len(s):
            if s[right] in chars:
                left = max(left, chars[s[right]] + 1)
            chars[s[right]] = right
            maxx = max(maxx, right - left + 1)
            right += 1
        return maxx
