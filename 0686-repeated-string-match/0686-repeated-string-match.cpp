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

    int updateHash(long long &hasa, char oldChar, char newChar, int size){
        hasa -= ((oldChar-'a'+1) * binpow(10,size-1))%M;
        hasa = (hasa*10)%M;
        hasa += (newChar-'a'+1);
        return hasa;
    }

    int repeatedStringMatch(string a, string b) {
        int hasb = hashh(b);
        string temp; int cnt=0;
        while(temp.size() < b.size()){
            temp += a; cnt++;
        }
        string dumy(temp.begin(), temp.begin()+b.size());
        
        long long hasa = hashh(dumy); int start = 0;
        if(hasa == hasb) return cnt;

        for(int i=b.size(); i<temp.size(); i++){
            hasa = updateHash(hasa, temp[start++], temp[i], dumy.size());
            if(hasa == hasb){
                return cnt;
            }
        }

        temp += a; cnt++;
        for(int i=temp.size()-a.size(); i<temp.size(); i++){
            hasa = updateHash(hasa, temp[start++], temp[i], dumy.size());
            if(hasa == hasb){
                return cnt;
            }
        }
        
        return -1;
    }
};
