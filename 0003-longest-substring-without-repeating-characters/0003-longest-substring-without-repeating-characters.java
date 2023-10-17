class Solution {
    public int lengthOfLongestSubstring(String s) {
        int left = 0, right = 0;
        int[] chars = new int[256];
        Arrays.fill(chars, -1);
        int maxx = 0;
        while (right < s.length()) {
            if (chars[s.charAt(right)] != -1) {
                left = Math.max(left, chars[s.charAt(right)] + 1);
            }
            chars[s.charAt(right)] = right;
            maxx = Math.max(maxx, right - left + 1);
            right++;
        }
        return maxx;
    }
}
