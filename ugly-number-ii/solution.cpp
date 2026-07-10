class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long , vector<long long> , greater<long long>> pq;
        unordered_set<long long> st;
        pq.push(1);
        st.insert(1);

        long long ans = 1;

        while(n>0){
            ans = pq.top();
            pq.pop();

            if(st.count(ans*2) == 0){
                pq.push(ans*2);
                st.insert(ans*2);
            }
            if(st.count(ans*3) == 0){
                pq.push(ans*3);
                st.insert(ans*3);
            }
            if(st.count(ans*5) == 0){
                pq.push(ans*5);
                st.insert(ans*5);
            }
            n--;
        }
       return (int)ans;
    }
};