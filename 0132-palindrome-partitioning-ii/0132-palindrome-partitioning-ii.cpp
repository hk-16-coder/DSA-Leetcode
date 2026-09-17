class Solution {
public:
    bool isPalindrome(string &s){
        int i = 0  , j = s.size() - 1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }

    int f(int idx , string& s , vector<int>& dp){
        int n = s.size();
        if(idx == n) return 0;
        if(dp[idx] != -1) return dp[idx];
        string temp = "";
        int mini = 1e9;
        for(int j = idx ; j<n ; j++){
            temp+=s[j];
            if(isPalindrome(temp)){
                int cost = 1 + f(j+1 , s , dp);
                mini = min(mini , cost);
            }
        }
        return dp[idx] = mini;
    }
    int minCut(string s) {
        vector<int> dp(s.size() , -1);
        return f(0 , s , dp) - 1;
    }
};