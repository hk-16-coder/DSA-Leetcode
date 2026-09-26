class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string , string> mpp;
        for(auto& it : knowledge){
            mpp[it[0]] = it[1];
        }
        string ans = "";
        int i = 0;
        while(i<s.size()){
            if(s[i] == '('){
                string key = "";
                while(s[i] != ')'){
                    i++;
                    if(s[i] != ')') key+=s[i];
                }
               
                if(mpp.count(key)){
                    ans += mpp[key];   
                }
                else ans += '?';
                i++;
            }

            else{
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};