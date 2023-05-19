class Solution {
public:
    int ispower(int n){
        int sum = 0;
        while(n > 0){
            sum+=pow(n%10,2);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int fast=n,slow=n;
        // cout<<fast<<" "<<slow<<endl;
        while(slow!=1 && fast!=1){
            slow = ispower(slow);
            fast = ispower(ispower(fast));
            // cout<<slow<<" "<<fast<<endl;
            if(fast == slow && fast!=1){
                return false;
            }
        }
        return true;
    }
};  