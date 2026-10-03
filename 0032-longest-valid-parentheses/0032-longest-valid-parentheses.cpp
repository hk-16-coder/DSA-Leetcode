class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n);

        stack<int> st;
        int maxi = 0;
        for(int i = 0 ; i<n ; i++){
            if(s[i] == '('){
                st.push(i);
            }

            else{
                if(!st.empty()){
                    int idx = st.top();
                    st.pop();

                    dp[i] = i - idx + 1;
                    if(idx >= 1) dp[i] += dp[idx-1];
                }
            }
            maxi = max(maxi , dp[i]);
        }
        return maxi;
    }
};