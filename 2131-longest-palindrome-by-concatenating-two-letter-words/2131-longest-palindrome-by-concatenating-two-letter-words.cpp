class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> mp;
        for(int i=0; i<words.size(); i++){
            mp[words[i]]++;
        }
        int count = 0; int even = 1;
        for(auto xx:mp){
            string d="nj";
            d[0] = xx.first[1];
            d[1] = xx.first[0];
            if(d == xx.first){
                if(mp[d]%2 == 0){
                    count += mp[d];
                }
                else{
                    even = 0;
                    count += mp[d]-1;
                }
            }
            else{
                if(mp[d] >= 1){
                   // if(mp[d]%2 == 0){
                        // count += mp[d];
                    // }
                    // else{
                    //     count += mp[d]-1;
                    // } 
                    int tem = min(mp[d],mp[xx.first]);
                    mp[d]-=tem;
                    mp[xx.first]-=tem;
                    count+=2*tem;
                }
            }
        }
            if(even==0) 
                count++;
        return count*2;
    }
};