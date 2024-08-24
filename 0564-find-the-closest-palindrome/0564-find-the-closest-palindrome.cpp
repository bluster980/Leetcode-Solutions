class Solution {
public:
    string nearestPalindromic(string n) {
       if (n.size() == 1)
           return to_string(stoi(n) - 1);

       int digitCnt = n.size();
       vector<long> candidates{};
       candidates.push_back(pow(10, digitCnt - 1) - 1); 
       candidates.push_back(pow(10, digitCnt) + 1);

       int mid = (digitCnt + 1) / 2;
       long pref = stol(n.substr(0, mid));

       vector<long> v = { pref, pref + 1, pref - 1 };
       for (long num : v) {
           string postfix = to_string(num);
           if (digitCnt % 2 == 1)
               postfix.pop_back();
           reverse(postfix.begin(), postfix.end());
           string cand = to_string(num) + postfix;
           candidates.push_back(stol(cand));
       }

       long res = 0, num = stol(n), minDiff = LONG_MAX;
       for (int i = 0; i < 5; i++) {
           if (candidates[i] != num &&
               abs(candidates[i] - num)< minDiff) {
               minDiff = abs(candidates[i] - num);
               res = candidates[i];
           }
           else if (abs(candidates[i] - num) == minDiff)
               res = min(res, candidates[i]);
       }
        return to_string(res);
    }
};