class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string combined = s + "#" + rev_s;

        vector<int> prefix(combined.size(), 0);

        for (int i = 1; i < combined.size(); i++) {
            int j = prefix[i - 1];
            
            while (j > 0 && combined[i] != combined[j]) {
                j = prefix[j - 1];
            }

            if (combined[i] == combined[j]) {
                j++;
            }

            prefix[i] = j;
        }

        int longest_palindrome_prefix_len = prefix.back();

        string non_palindrome_suffix = s.substr(longest_palindrome_prefix_len);
        reverse(non_palindrome_suffix.begin(), non_palindrome_suffix.end());

        return non_palindrome_suffix + s;
    }
};