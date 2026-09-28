class Solution {
public:
    bool check(int i , int j , string&s){
        if(i == j)return true;
        while(i<j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0 ; i<n ; i++){
            for(int j = i ; j<n ; j++){
                if(check(i , j , s)) ans++;
            }
        }
        return ans;
    }
};