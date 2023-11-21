using ll = long long int;
class Solution {
public:
    ll mod = 1e9 + 7;
    int rev(int num){
        int ans  = 0;
        while(num){
            ans = ans*10 + num % 10;
            num /= 10;
        }
        
        return ans;
    }
    
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<ll,ll> mp;
        
        for(int el : nums){
            mp[el - rev(el)]++;
        }
        
        ll sum = 0;
        for(auto el : mp){
            ll add = (el.second * (el.second - 1))/2;
            sum = (sum % mod + add % mod) % mod;
        }
        
        return sum;
    }
};