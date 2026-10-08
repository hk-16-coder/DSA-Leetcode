class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int len = s.size();
        int cnt = 0;
        for(int i = 0 ; i<len ; i++){
            if(s[i] == '(') {
               if(cnt>0) ans+=s[i];
            cnt++;
            } 
            else {
                cnt--;
                if(cnt>0) ans+=s[i];
            }   
        }

        return ans;
    }
};