class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int arr[30]={0};
        for(int i=0;i<allowed.length();i++){
            int a = allowed[i]-'a';
            arr[a]+=1;
        }
        int res=0;
        for(int i=0;i<words.size();i++){
            int b = 1;
            for(int j=0;j<words[i].size();j++){
                int c= words[i][j]-'a';
                if(arr[c]==0){
                    b=0;
                    break;
                }
            }
            if(b==1){
                res+=1;
            }
        }
        return res;
    }
};