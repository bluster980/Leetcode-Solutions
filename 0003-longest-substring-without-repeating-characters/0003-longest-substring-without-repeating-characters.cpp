class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        vector<int> chars(256, -1);
        int maxx = 0;
        while (right < s.size()) {
            if (chars[s[right]] != -1) {
                left = max(left, chars[s[right]] + 1);
            }
            chars[s[right]] = right;
            maxx = max(maxx, right - left + 1);
            right++;
        }
        return maxx;
    }
};