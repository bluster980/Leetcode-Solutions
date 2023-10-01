#define MOD INT_MAX
class Solution {
public:

    bool isSubstring(string check, string b, int hash_val) {
        int curr_hash = 0;
        int n = check.length();
        int m = b.length();
        long long  mul = 1;
        for(int i = 0 ; i < b.length(); i++) {
            curr_hash = (curr_hash + ((check[i] - 'a'+1)*mul)%MOD)%MOD;
            mul = (mul*11)%MOD;
        }
        mul /= 11;
        if(curr_hash == hash_val) return 1;
        for(int i = 1; i <= n-m; i++) {
            curr_hash -= (check[i-1] - 'a'+1);
            curr_hash /= 11;
            curr_hash = (curr_hash + ((check[i+m-1] - 'a'+1)*mul)%MOD)%MOD;
            if(curr_hash == hash_val)
                return 1;
        }
        return 0;
    }

    int repeatedStringMatch(string a, string b) {
        int m = a.length(), n = b.length();
        int hash_val = 0;
        long long mul = 1;
        for(char x: b) {
            hash_val = (hash_val + ((x - 'a'+1)*mul)%MOD)%MOD;
            mul = (mul*11)%MOD;
        }
        string check = "";
        int count = 0;
        while(check.size() < b.size()) {
            count++;
            check += a;
        }
        if(isSubstring(check, b, hash_val)) return count;
        if(isSubstring(check + a, b, hash_val)) return count+1;
        return -1;
    }
};