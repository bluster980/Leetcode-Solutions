class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int j = 0, maxx = 0;
        map<int, int> count;
        for (int i = 0; i < s.length(); ++i) {
            maxx = max(maxx, ++count[s[i]]);
            if (j - maxx < k)
                j++;
            else
                count[s[i - j]]--;
        }
        return j;
    }
};