class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(st.size()==0){
               st.push(ch);
            }else{
                char topChar = st.top();
                if(ch=='B'){
                   if(topChar=='A')st.pop();
                   else
                   {st.push(ch);}
                }else if(ch=='D'){
                    if(topChar=='C')st.pop();
                    else
                    {st.push(ch);}
                }else{
                    st.push(ch);
                }
            }
        }
        return st.size();
    }
};