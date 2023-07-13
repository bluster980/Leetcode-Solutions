class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ass) {
        stack<int> st; int i=0;
        while(i<ass.size()){
            if(!st.empty() && ass[i] < 0){
                if((ass[i]>0 && st.top()>0) || (ass[i]<0 && st.top()<0)){
                    st.push(ass[i]); i++;
                }
                else if(ass[i] < 0){
                    if(st.top() < 0) {st.push(ass[i]); i++;}
                    else{
                        if(st.top() > abs(ass[i])){
                            i++;
                        }
                        else if(st.top() == abs(ass[i])){
                            st.pop(); i++;
                        }
                        else{
                            st.pop();
                        }
                    }
                }
                else 
                    {st.push(ass[i]); i++;}
            }
            else{
                st.push(ass[i]); i++;
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top()); st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};