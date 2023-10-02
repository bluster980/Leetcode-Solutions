class Solution {
#define M INT_MAX;
public:
    long long binpow(int a, int b){
        long long ans = 1;
        while(b>0){
            if(b&1){
                ans = (ans * 1ll * a) % M;
            }
            a = (a * 1ll * a) % M;
            b >>= 1;
        }
        return ans;
    }

    int hashh(string s){
        long long targetHash = 0; int size = s.size()-1;
        for(int i=0; i<s.size(); i++){
            targetHash += ((s[i]-'a'+1) * binpow(10,size--));
        }
        return targetHash % M;
    }
    int repeatedStringMatch(string a, string b) {
        int hasb = hashh(b);
        string temp; int cnt=0;
        while(temp.size() < b.size()){
            temp += a; cnt++;
        }
        string dumy;
        for(int i=0; i<b.size(); i++){
            dumy.push_back(temp[i]);
        }
        long long hasa = hashh(dumy); int start = 0;
        if(hasa == hasb) return cnt;
        for(int i=b.size(); i<temp.size(); i++){
            hasa -= ((temp[start++]-'a'+1) * binpow(10,dumy.size()-1))%M;
            hasa = (hasa*10)%M;
            hasa += (temp[i]-'a'+1);
            if(hasa == hasb){
                return cnt;
            }
            // cout<<hasa<<" "<<hasb<<endl;
        }
        int fghj = temp.size();
        temp += a; cnt++;
        for(int i=fghj; i<temp.size(); i++){
            hasa -= ((temp[start++]-'a'+1) * binpow(10,dumy.size()-1))%M;
            hasa = (hasa*10)%M;
            hasa += (temp[i]-'a'+1);
            if(hasa == hasb){
                return cnt;
            }
            // cout<<hasa<<" "<<hasb<<endl;
        }
        // cout<<temp<<endl;
        return -1;
    }
};