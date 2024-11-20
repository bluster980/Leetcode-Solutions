class Solution {
public:
    int f(int mid,string &s,int k){
        vector<int>cnt(3,0);
        for(int i=0;i<mid;i++){
            cnt[s[i]-'a']++;
            int res=0;
            for(int j=0;j<3;j++){
                if(cnt[j]>=k)res++;
            }
            if(res==3)return 1;
        }
        int l=mid-1;
        for(int i=s.size()-1;i>=0&&l>=0;i--,l--){
            cnt[s[i]-'a']++;
            cnt[s[l]-'a']--;
            int res=0;
            for(int j=0;j<3;j++){
                if(cnt[j]>=k)res++;
            }
            if(res==3)return 1;
        }
        return 0;
    }
    int takeCharacters(string s, int k) {
        int l=0,h=s.size();
        if(!k)return 0;
        while(l<=h){
            int mid=(l+h)/2;
            if(f(mid,s,k))h=mid-1;
            else l=mid+1;
        }
        if(l==s.size()+1)return -1;
        return h+1;
    }
};