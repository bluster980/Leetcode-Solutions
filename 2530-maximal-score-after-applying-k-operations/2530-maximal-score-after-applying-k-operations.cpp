class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans =0;
        priority_queue<int> pq;
        for(auto x : nums) pq.push(x);
        while(k--){
            int temp=pq.top();
            pq.pop();
            ans+=temp;
            if(temp%3 !=0) {
                
                temp = temp/3;
                temp++;
            }
            else{
                temp = temp/3;
            }
            pq.push(temp);
            cout<<temp<<endl;

        }
     return ans;
        
    }
};