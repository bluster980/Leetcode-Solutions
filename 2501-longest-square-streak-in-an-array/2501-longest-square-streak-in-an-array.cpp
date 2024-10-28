class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        if (nums.size() <= 1) {
            return -1;
        }
        int longest = 0;
        unordered_set<long long> st(nums.begin(), nums.end());
        for (int num : nums) {
            int count = 1; 
            long long current = num;
            while (st.find(current * current) != st.end()) {
                current = current * current; 
                count++;                     
            }

            if (count >= 2) { 
                longest = max(longest, count);
            }
        }

        return longest >= 2 ? longest : -1;
    }
};