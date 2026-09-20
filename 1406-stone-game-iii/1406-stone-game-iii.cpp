class Solution {
public:
    int f(int idx , vector<int>& stoneValue ,  vector<int>& dp){
        if(idx == stoneValue.size()) return 0;
        if(dp[idx] != -1) return dp[idx];

        int sum = 0;
        int ans = -1e9;

        for(int x = 1 ; x<=3 ; x++){
            if(idx + x > stoneValue.size()) break;

            sum += stoneValue[idx+x-1];
            int score = sum - f(idx+x , stoneValue , dp);

            ans = max(ans,score);
        }
        return dp[idx] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size() , -1);
        int diff = f(0 , stoneValue , dp);

        if(diff>0) return "Alice";
        if(diff<0) return "Bob";
        return "Tie";
    }
};