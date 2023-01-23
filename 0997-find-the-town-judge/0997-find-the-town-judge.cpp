class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int> mp; vector<int> v(n+1);
        for(int i=0; i<trust.size(); i++){
            mp[trust[i][0]] = trust[i][1]; v[trust[i][1]]++;
        }
        int i = 1;
        for(auto xx:mp){
            if(i<=n && xx.first == i) 
                i++;
            else{
                break;
            }
        }
        // cout<<v[i]<<endl;
        if(i<=n && v[i] == n-1) return i;
        return -1;
    }
};