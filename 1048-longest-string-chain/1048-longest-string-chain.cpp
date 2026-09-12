class Solution {
public:
    bool check(string& a , string& b){
        if(a.size() + 1 != b.size()) return false;
        int cnt = 0;
        int  i = 0 ; int j = 0;
        while(i<a.size() && j<b.size()){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else{
                cnt++;
                j++;
                if(cnt>1)return false;
            }
        }
        return true;
    }

    int f(int idx , int prev , vector<string>& words , vector<vector<int>>& dp){
        if(idx == words.size()) return 0;
        if(dp[idx][prev + 1] != -1) return dp[idx][prev+ 1];

        int len = f(idx+1 , prev , words , dp); // notTake
        if(prev == -1 || check(words[prev] , words[idx])){
            len = max(len , 1 + f(idx+1 , idx , words , dp));
        }

        return dp[idx][prev+1] = len;
    }
    int longestStrChain(vector<string>& words){
        sort(words.begin() , words.end() , [](string& a , string& b){
            return a.size() < b.size();
        });

        int n = words.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1,-1));
        return f(0 , -1 , words , dp);
    }
};