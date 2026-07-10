class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int cnt = 0;
        int i = 0;
        while(i<num.size() && cnt<k){
            while(!st.empty() && num[i]<st.top()) {
                st.pop();
                cnt++;
                if(cnt==k) break;
            }
            st.push(num[i]);
            i++;
        }
        
        while(i<num.size()){
            st.push(num[i]);
            i++;
        }

        while(cnt<k){
            st.pop();
            cnt++;
        }
        
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        while(!ans.empty() && ans[0] == '0') ans.erase(ans.begin());

        if(ans.empty()) return "0";
        return ans;
    }
};