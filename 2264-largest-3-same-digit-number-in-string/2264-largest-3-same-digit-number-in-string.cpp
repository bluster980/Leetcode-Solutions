class Solution {
public:
    string largestGoodInteger(string num) {
        bool flag = false;
        string temp; temp.push_back(num[0]); temp.push_back(num[1]); temp.push_back(num[2]); int maxx = 0; 
        if(temp[0]==temp[1] && temp[1]==temp[2]) maxx = max(maxx,stoi(temp));
        if(temp[0]==temp[1] && temp[1]==temp[2] && temp[0]=='0') flag = true;
        for(int i=3; i<num.size(); i++){
            temp.erase(temp.begin()); temp.push_back(num[i]);
            if(temp[0]==temp[1] && temp[1]==temp[2]) maxx = max(maxx,stoi(temp));
            if(temp[0]==temp[1] && temp[1]==temp[2] && temp[0]=='0') flag = true;
        }
        if(maxx == 0 && flag) return "000";
        else if(maxx == 0) return "";
        return to_string(maxx);
    }
};