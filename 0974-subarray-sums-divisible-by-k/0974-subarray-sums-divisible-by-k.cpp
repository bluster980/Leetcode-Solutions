class Solution {
public:
    int subarraysDivByK(vector<int>& v, int k) {
        unordered_map<int,int> mp; mp[0]++;
        int temp = 0; int count = 0;
        for(int i=0; i<v.size(); i++){
            temp+=v[i];
            int rem = temp%k;
            if(rem < 0) rem+=k;
            if(mp.find(rem)!=mp.end()){
                count+=mp[rem];
            }
            mp[rem]++;
        }
        return count;
    }
};
