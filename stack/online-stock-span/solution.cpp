class StockSpanner {
public:
    stack<pair<int,int>> st;
    int idx = -1;
    StockSpanner() {
        idx = -1;
        st = stack<pair<int,int>>();
    }
    
    int next(int price) {
        int ans = 0;
        idx+=1;
        while(!st.empty() && st.top().first <= price) st.pop();
        if(st.empty()) ans = idx + 1;
        else ans = idx - st.top().second;
        st.push({price,idx});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */