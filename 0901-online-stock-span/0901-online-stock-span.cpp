class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    stack<pair<int,int>> st; int in = 0;
    int next(int price) {
        int ans = 0;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        if(!st.empty()) ans = st.top().second;
        in++; st.push({price,in});
        return in-ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */