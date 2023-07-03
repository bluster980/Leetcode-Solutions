class Solution {
public:
    bool buddyStrings(string s, string g) {
        if(s.size() == 1) return false;
        unordered_set<char> st;
        int first = INT_MIN,second = INT_MIN;
        for(int i=0; i<s.size(); i++){
            st.insert(s[i]);
            if(s[i] != g[i]){
                if(first == INT_MIN) {first = i;}
                else {second = i; break;}
            }
        }
        // for(int i=0; i<s.size(); i++){
        // }
        if(first!=INT_MIN && second!=INT_MIN){
            swap(s[first],s[second]);
            return s==g;
        }
        return s==g && (st.size()<s.size());
    }
};