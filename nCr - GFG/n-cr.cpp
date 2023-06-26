//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    const int M = 1e9+7;
    #define ll long long
    ll binMultiply(ll a, ll b){ //Till ~10^18.
    	ll ans = 0;	
    	while(b > 0){
    		if(b&1){
    			ans = (ans + a) % M;
    		}
    		a = (a + a) % M;
    		b >>= 1;
    	}
    	return ans;
    }
    
    ll binExp(ll a, ll b){
    	ll ans = 1;
    	while(b>0){
    		if(b&1){
    			ans = binMultiply(ans,a);
    		}
    		a = binMultiply(a,a);
    		b >>= 1;
    	}
    	return ans;
    }
    ll nCr(ll n, ll r){
        // ll fact[1001]; fact[0]=1;
        // for(ll i=1; i<n; i++){
        //     fact[i] = (i*1ll*fact[i-1])%M;
        // }
    //     ll N = 1001;
    // 	ll facs[N]; facs[0] = 1;
    // 	for(ll i=1; i<N; i++){
    // 		facs[i] = (i*1ll*facs[i-1]) % M;
    // 	}
    // 	cout<<facs[1000]<<endl;
    //     // cout<<fact[1000]<<endl;
    //     ll den = (facs[n-r]*1ll*facs[r]);
    //     return (facs[n] * 1ll * binExp(den,M-2)) % M;
        // return 0;
        ll N = 1001;
	ll fac[N]; fac[0] = 1;
	for(ll i=1; i<N; i++){
		fac[i] = (i*1ll*fac[i-1]) % M;
	}
	// cout<<fac[1000];
	ll num = fac[n];
	ll den = fac[n-r]*1ll*fac[r];
	ll ans = num*1ll*binExp(den,M-2);
// 	cout<<ans%M<<endl;
	return (n<r)?0:ans%M;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends