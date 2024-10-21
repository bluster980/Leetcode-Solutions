#include <unordered_set>
#include <string>
using namespace std;

class Solution {

public:

    int maxUniqueSplit(string s) {
        unordered_set<string> uniqueSubstrings;
        return dfs(s, 0, uniqueSubstrings);
    }

private:

    int dfs(const string &s, int start, unordered_set<string> &uniqueSubstrings) {
        if (start == s.size()) {
            return 0;
        }
        
        int maxSplits = 0;
        string currentSubstring;
        
        for (int i = start; i < s.size(); ++i) {
            currentSubstring += s[i];
            
            if (uniqueSubstrings.find(currentSubstring) == uniqueSubstrings.end()) {
                uniqueSubstrings.insert(currentSubstring);

                maxSplits = max(maxSplits, 1 + dfs(s, i + 1, uniqueSubstrings));
                uniqueSubstrings.erase(currentSubstring);  
            }
        }
        
        return maxSplits;
    }
};