class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1==s2) return true;
        if(s1.size() > s2.size()) return false;
        map<char,int> ss,temp;
        for(int i=0; i<s1.size(); i++){
            ss[s1[i]]++;
        }
        for(int i=0; i<s1.size(); i++){
            temp[s2[i]]++;
        }
        if(ss==temp){
            return true;
        }
        int zz = 0;
        for(int i=s1.size(); i<s2.size(); i++){
            if(ss==temp){
                return true;
            }
            if(temp[s2[zz]]==1)
                temp.erase(s2[zz]);
            else{
                temp[s2[zz]]--;
            }
            temp[s2[i]]++;
            zz++;
            if(ss==temp){
                return true;
            }
        }
        return false;
    }
};