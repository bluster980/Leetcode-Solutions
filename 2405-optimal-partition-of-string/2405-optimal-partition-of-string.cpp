class Solution {
public:
    int partitionString(string s) {
        set<char> st;
        int count = 1;
        for(int i=0; i<s.size(); i++){
            int bf = st.size();
            st.insert(s[i]);
            int af = st.size();
            if(bf==af){
                count++;
                set<char> x;
                st = x;
                st.insert(s[i]);
            }
            
        }
        return max(count,1);
    }
};