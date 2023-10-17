class Solution {
    public int lengthOfLongestSubstring(String s) {
        int left = 0, right = 0;
        HashMap<Character, Integer> chars = new HashMap<>();
        int maxx = 0;
        while (right < s.length()) {
            if (chars.containsKey(s.charAt(right))) {
                left = Math.max(left, chars.get(s.charAt(right)) + 1);
            }
            chars.put(s.charAt(right), right);
            maxx = Math.max(maxx, right - left + 1);
            right++;
        }
        return maxx;
    }
}
