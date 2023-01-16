class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        for(int i=0; i<tasks.size(); i++){
            mp[tasks[i]]++;
        }
        int count = 0;
        for(auto xx:mp){
            if(xx.second == 1) return -1;
            // cout<<xx.first<<" "<<xx.second<<endl;
            count += xx.second/3; xx.second%=3;
            count += xx.second/2; xx.second%=2;
            if(xx.second > 0) count++;
        }
        return count;
    }
};