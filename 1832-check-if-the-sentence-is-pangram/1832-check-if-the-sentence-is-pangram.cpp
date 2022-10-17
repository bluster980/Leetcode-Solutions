class Solution {
public:
    bool checkIfPangram(string s) {
        set<char> st;
        for(int i=0; i<s.size(); i++){
            
            st.insert(s[i]);
        }
        if(st.size()<26) return false; 
        char x = 'a';
        for(auto xx:st){
            // cout<<xx<<" ";
            if(xx!=x) return false;
            x++;
        }
        return true;
    }
};