class Solution {
public: 
    bool parse_and(vector<int>& arr){
        int ans = arr[0];
        for(int i = 1 ; i<arr.size() ; i++){
            ans &= arr[i];
        }
        return ans;
    }

    bool parse_or(vector<int>& arr){
        int ans = arr[0];
        for(int i = 1 ; i<arr.size() ; i++){
            ans |= arr[i];
        }
        return ans;
    }

    bool parseBoolExpr(string s) {
        int n = s.size();
        stack<char> st;

        for(int i = 0 ; i<n ; i++){
            if(s[i] == ',') continue;
            if(s[i] == ')'){
                vector<int> arr;
                while(st.top() != '&' && st.top() != '|' && st.top() != '!'){
                    char c = st.top();
                    st.pop();
                    if(c == 't') arr.push_back(1);
                    else if(c == 'f') arr.push_back(0);
                }

                char op = st.top();
                st.pop();

                if(op == '&'){
                    if(parse_and(arr)) st.push('t');
                    else st.push('f');
                }

                else if(op == '|'){
                    if(parse_or(arr)) st.push('t');
                    else st.push('f');
                }

                else if(op == '!'){
                    if(arr[0] == 0) st.push('t');
                    else st.push('f');
                }
            }
            else st.push(s[i]);
        }

        if(st.top() == 't') return true;
        return false;
    }
};