class Solution {
public:
    vector<vector<string>> ans;
    bool check_palindrome(string s){
        int n = s.size();
        int i = 0 ;
        int j = n-1;
        while(i<=j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void generate (int idx, vector<string>& temp,  string& s){
            int n = s.size();
            if(idx == n){
                ans.push_back(temp);
                return;
            }
            for(int i = idx ; i<n ; i++){
                string curr = s.substr(idx,i-idx+1);
                if(check_palindrome(curr)){
                  temp.push_back(curr);
                  generate(i+1,temp,s);
                  temp.pop_back();
                }
            }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        generate(0,temp,s);
        return ans;
    }
};