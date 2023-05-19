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
        unordered_set<int> st;
        int temp = n,bf,af;
        while(af!=bf){
            bf = st.size();
            temp = ispower(temp);
            st.insert(temp);
            af = st.size();
            if(temp == 1) return true;
        }
        return false;
    }
};  