class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int> st;
        for(int i=0; i<dictionary.size(); i++){
            st[dictionary[i]]++;
        }
        string word="",ans="";
        sentence += ' ';
        for(auto i: sentence){
            if(i==' '){
                if(ans.size()>0) ans += ' ';
                string temp = "";
                for(auto j: word){
                    temp += j;
                    if(st.count(temp)) {
                        break;
                    }
                }
                ans += temp;
                word = "";
            } else word += i;
        }
        return ans;
    }
};